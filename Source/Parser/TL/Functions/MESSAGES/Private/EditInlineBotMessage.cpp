#include "../Public/EditInlineBotMessage.h"


//begin namespace block
namespace MESSAGES
{

EditInlineBotMessage::EditInlineBotMessage()
{
	this->_ConstructorID = 319564933;
	this->_ContentRelated = true;
}

EditInlineBotMessage::EditInlineBotMessage(bool no_webpage, COMMON::InputBotInlineMessageID*  id, FString message, PRIVATE::ReplyMarkup*  reply_markup, TArray<PRIVATE::MessageEntity*>  entities)
{
	this->_ConstructorID = 319564933;
	this->_ContentRelated = true;
	this->no_webpage = no_webpage;
	this->id = id;
	this->message = message;
	this->reply_markup = reply_markup;
	this->entities = entities;
}
void EditInlineBotMessage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(no_webpage)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!message.IsEmpty())
	{
		Flags |= (1 << 11);
	}
	else
	{
		Flags |= 0;
	}
	if(reply_markup)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(entities.Num())
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->id->OnSend(Writer);
	Writer.TGWriteString(this->message);
	if(!this->reply_markup)
	{
	this->reply_markup->OnSend(Writer);
	}
	if(this->entities.Num())
	{
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->entities.Num());
	for(auto X : this->entities)
	{
	if(!X)
	{
	X->OnSend(Writer);
	}
	}
	}
}


void EditInlineBotMessage::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
EditInlineBotMessage::~EditInlineBotMessage()
{

}
}//end namespace block
