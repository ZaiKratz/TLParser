#include "../Public/SendMessage.h"


//begin namespace block
namespace MESSAGES
{

SendMessage::SendMessage()
{
	this->_ConstructorID = 2051180794;
	this->_ContentRelated = true;
}

SendMessage::SendMessage(bool no_webpage, bool silent, bool background, bool clear_draft, PRIVATE::InputPeer* peer, int32 reply_to_msg_id, FString message, unsigned long long random_id, PRIVATE::ReplyMarkup* reply_markup, TArray<PRIVATE::MessageEntity*> entities)
{
	this->_ConstructorID = 2051180794;
	this->_ContentRelated = true;
	this->no_webpage = no_webpage;
	this->silent = silent;
	this->background = background;
	this->clear_draft = clear_draft;
	this->peer = peer;
	this->reply_to_msg_id = reply_to_msg_id;
	this->message = message;
	this->random_id = random_id;
	this->reply_markup = reply_markup;
	this->entities = entities;
}
void SendMessage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!no_webpage)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!silent)
	{
		Flags |= (1 << 5);
	}
	else
	{
		Flags |= 0;
	}
	if(!background)
	{
		Flags |= (1 << 6);
	}
	else
	{
		Flags |= 0;
	}
	if(!clear_draft)
	{
		Flags |= (1 << 7);
	}
	else
	{
		Flags |= 0;
	}
	if(!reply_to_msg_id)
	{
		Flags |= (1 << 0);
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
	if(!this->reply_to_msg_id)
	{
	Writer.WriteInt(this->reply_to_msg_id);
	}
	Writer.TGWriteString(this->message);
	Writer.WriteLong(this->random_id);
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


void SendMessage::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
}
SendMessage::~SendMessage()
{

}
}//end namespace block
