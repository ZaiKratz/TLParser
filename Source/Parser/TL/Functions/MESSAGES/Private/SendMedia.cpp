#include "../Public/SendMedia.h"


//begin namespace block
namespace MESSAGES
{

SendMedia::SendMedia()
{
	this->_ConstructorID = -923703407;
	this->_ContentRelated = true;
}

SendMedia::SendMedia(bool silent, bool background, bool clear_draft, TLBaseObject*  peer, int32 reply_to_msg_id, TLBaseObject*  media, unsigned long long random_id, TLBaseObject*  reply_markup)
{
	this->_ConstructorID = -923703407;
	this->_ContentRelated = true;
	this->silent = silent;
	this->background = background;
	this->clear_draft = clear_draft;
	this->peer = peer;
	this->reply_to_msg_id = reply_to_msg_id;
	this->media = media;
	this->random_id = random_id;
	this->reply_markup = reply_markup;
}
void SendMedia::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(silent)
	{
		Flags |= (1 << 5);
	}
	else
	{
		Flags |= 0;
	}
	if(background)
	{
		Flags |= (1 << 6);
	}
	else
	{
		Flags |= 0;
	}
	if(clear_draft)
	{
		Flags |= (1 << 7);
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
	if(reply_markup)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->peer->OnSend(Writer);
	if(this->reply_to_msg_id)
	{
	Writer.WriteInt(this->reply_to_msg_id);
	}
	this->media->OnSend(Writer);
	Writer.WriteLong(this->random_id);
	if(this->reply_markup)
	{
	this->reply_markup->OnSend(Writer);
	}
}


void SendMedia::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
	this->_Responded = true;
}
SendMedia::~SendMedia()
{
	if(this->peer)
	{
		delete this->peer;
	}
	if(this->media)
	{
		delete this->media;
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
