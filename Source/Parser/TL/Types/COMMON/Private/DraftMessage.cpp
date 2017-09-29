#include "../Public/DraftMessage.h"


//begin namespace block
namespace COMMON
{

DraftMessage::DraftMessage()
{
	this->_ConstructorID = -40996577;
}

DraftMessage::DraftMessage(bool no_webpage, int32 reply_to_msg_id, FString message, TArray<PRIVATE::MessageEntity*>  entities, FDateTime date)
{
	this->_ConstructorID = -40996577;
	this->no_webpage = no_webpage;
	this->reply_to_msg_id = reply_to_msg_id;
	this->message = message;
	this->entities = entities;
	this->date = date;
}
void DraftMessage::OnSend(BinaryWriter& Writer)
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
	if(reply_to_msg_id)
	{
		Flags |= (1 << 0);
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

	if(!this->reply_to_msg_id)
	{
	Writer.WriteInt(this->reply_to_msg_id);
	}
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
	Writer.TGWriteDate(this->date);
}


void DraftMessage::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 1)) != 0) 
	{
		no_webpage = true;
	}
	if((Flags & (1 << 0)) != 0) 
	{
	reply_to_msg_id = Reader.ReadInt();
	}
	message = Reader.TGReadString();
	if((Flags & (1 << 3)) != 0) 
	{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len9772 = Reader.ReadInt();
	for(int32 i = 0; i < Len9772; i++)
	{
	auto X = reinterpret_cast<PRIVATE::MessageEntity*>(Reader.TGReadObject());
	entities.Add(X);
	}
	}
	date = Reader.TGReadDate();
	this->_Responded = true;
}
DraftMessage::~DraftMessage()
{

}
}//end namespace block
