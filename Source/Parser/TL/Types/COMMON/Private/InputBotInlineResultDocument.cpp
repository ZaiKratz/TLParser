#include "../Public/InputBotInlineResultDocument.h"


//begin namespace block
namespace COMMON
{

InputBotInlineResultDocument::InputBotInlineResultDocument()
{
	this->_ConstructorID = -459324;
}

InputBotInlineResultDocument::InputBotInlineResultDocument(FString id, FString type, FString title, FString description, COMMON::InputDocument*  document, PRIVATE::InputBotInlineMessage*  send_message)
{
	this->_ConstructorID = -459324;
	this->id = id;
	this->type = type;
	this->title = title;
	this->description = description;
	this->document = document;
	this->send_message = send_message;
}
void InputBotInlineResultDocument::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!title.IsEmpty())
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!description.IsEmpty())
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteString(this->id);
	Writer.TGWriteString(this->type);
	Writer.TGWriteString(this->title);
	Writer.TGWriteString(this->description);
	this->document->OnSend(Writer);
	this->send_message->OnSend(Writer);
}


void InputBotInlineResultDocument::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	id = Reader.TGReadString();
	type = Reader.TGReadString();
	if((Flags & (1 << 1)) != 0) 
	{
	title = Reader.TGReadString();
	}
	if((Flags & (1 << 2)) != 0) 
	{
	description = Reader.TGReadString();
	}
	document = reinterpret_cast<COMMON::InputDocument* >(Reader.TGReadObject());
	send_message = reinterpret_cast<PRIVATE::InputBotInlineMessage* >(Reader.TGReadObject());
	this->_Responded = true;
}
InputBotInlineResultDocument::~InputBotInlineResultDocument()
{

}
}//end namespace block
