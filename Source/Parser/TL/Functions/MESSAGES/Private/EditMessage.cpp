#include "../Public/EditMessage.h"


//begin namespace block
namespace MESSAGES
{

EditMessage::EditMessage()
{
	this->_ConstructorID = -829299510;
	this->_ContentRelated = true;
}

EditMessage::EditMessage(bool no_webpage, TLBaseObject*  peer, int32 id, FString message, TLBaseObject*  reply_markup, TArray<TLBaseObject*>  entities)
{
	this->_ConstructorID = -829299510;
	this->_ContentRelated = true;
	this->no_webpage = no_webpage;
	this->peer = peer;
	this->id = id;
	this->message = message;
	this->reply_markup = reply_markup;
	this->entities = entities;
}
void EditMessage::OnSend(BinaryWriter& Writer)
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

	this->peer->OnSend(Writer);
	Writer.WriteInt(this->id);
	Writer.TGWriteString(this->message);
	if(this->reply_markup)
	{
	this->reply_markup->OnSend(Writer);
	}
	if(this->entities.Num())
	{
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->entities.Num());
	for(auto X : this->entities)
	{
	if(X)
	{
	X->OnSend(Writer);
	}
	}
	}
}


void EditMessage::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
	this->_Responded = true;
}
EditMessage::~EditMessage()
{
	if(this->peer)
	{
		delete this->peer;
	}
	if(this->reply_markup)
	{
		delete this->reply_markup;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
