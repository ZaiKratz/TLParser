#include "../Public/InputBotInlineMessageText.h"


//begin namespace block
namespace COMMON
{

InputBotInlineMessageText::InputBotInlineMessageText()
{
	this->_ConstructorID = -2021995203;
}

InputBotInlineMessageText::InputBotInlineMessageText(bool no_webpage, FString message, TArray<PRIVATE::MessageEntity*> entities, PRIVATE::ReplyMarkup* reply_markup)
{
	this->_ConstructorID = -2021995203;
	this->no_webpage = no_webpage;
	this->message = message;
	this->entities = entities;
	this->reply_markup = reply_markup;
}
void InputBotInlineMessageText::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!no_webpage)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(entities.Num())
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!reply_markup)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteString(this->message);
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
	if(!this->reply_markup)
	{
	this->reply_markup->OnSend(Writer);
	}
}


void InputBotInlineMessageText::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		no_webpage = true;
	}
	message = Reader.TGReadString();
	if((Flags & (1 << 1)) != 0) 
	{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len5190 = Reader.ReadInt();
	for(int32 i = 0; i < Len5190; i++)
	{
	auto X = reinterpret_cast<PRIVATE::MessageEntity*>(Reader.TGReadObject());
	entities.Add(X);
	}
	}
	if((Flags & (1 << 2)) != 0) 
	{
	reply_markup = reinterpret_cast<PRIVATE::ReplyMarkup*>(Reader.TGReadObject());
	}
}
InputBotInlineMessageText::~InputBotInlineMessageText()
{

}
}//end namespace block
