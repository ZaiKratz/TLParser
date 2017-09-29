#include "../Public/BotInlineMediaResult.h"


//begin namespace block
namespace COMMON
{

BotInlineMediaResult::BotInlineMediaResult()
{
	this->_ConstructorID = 400266251;
}

BotInlineMediaResult::BotInlineMediaResult(FString id, FString type, COMMON::Photo*  photo, COMMON::Document*  document, FString title, FString description, PRIVATE::BotInlineMessage*  send_message)
{
	this->_ConstructorID = 400266251;
	this->id = id;
	this->type = type;
	this->photo = photo;
	this->document = document;
	this->title = title;
	this->description = description;
	this->send_message = send_message;
}
void BotInlineMediaResult::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(photo)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(document)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!title.IsEmpty())
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(!description.IsEmpty())
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteString(this->id);
	Writer.TGWriteString(this->type);
	if(!this->photo)
	{
	this->photo->OnSend(Writer);
	}
	if(!this->document)
	{
	this->document->OnSend(Writer);
	}
	Writer.TGWriteString(this->title);
	Writer.TGWriteString(this->description);
	this->send_message->OnSend(Writer);
}


void BotInlineMediaResult::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	id = Reader.TGReadString();
	type = Reader.TGReadString();
	if((Flags & (1 << 0)) != 0) 
	{
	photo = reinterpret_cast<COMMON::Photo* >(Reader.TGReadObject());
	}
	if((Flags & (1 << 1)) != 0) 
	{
	document = reinterpret_cast<COMMON::Document* >(Reader.TGReadObject());
	}
	if((Flags & (1 << 2)) != 0) 
	{
	title = Reader.TGReadString();
	}
	if((Flags & (1 << 3)) != 0) 
	{
	description = Reader.TGReadString();
	}
	send_message = reinterpret_cast<PRIVATE::BotInlineMessage* >(Reader.TGReadObject());
	this->_Responded = true;
}
BotInlineMediaResult::~BotInlineMediaResult()
{

}
}//end namespace block
