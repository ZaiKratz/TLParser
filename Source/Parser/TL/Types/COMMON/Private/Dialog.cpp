#include "../Public/Dialog.h"


//begin namespace block
namespace COMMON
{

Dialog::Dialog()
{
	this->_ConstructorID = -455150117;
}

Dialog::Dialog(bool pinned, PRIVATE::Peer*  peer, int32 top_message, int32 read_inbox_max_id, int32 read_outbox_max_id, int32 unread_count, int32 unread_mentions_count, COMMON::PeerNotifySettings*  notify_settings, int32 pts, COMMON::DraftMessage*  draft)
{
	this->_ConstructorID = -455150117;
	this->pinned = pinned;
	this->peer = peer;
	this->top_message = top_message;
	this->read_inbox_max_id = read_inbox_max_id;
	this->read_outbox_max_id = read_outbox_max_id;
	this->unread_count = unread_count;
	this->unread_mentions_count = unread_mentions_count;
	this->notify_settings = notify_settings;
	this->pts = pts;
	this->draft = draft;
}
void Dialog::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(pinned)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(pts)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(draft)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->peer->OnSend(Writer);
	Writer.WriteInt(this->top_message);
	Writer.WriteInt(this->read_inbox_max_id);
	Writer.WriteInt(this->read_outbox_max_id);
	Writer.WriteInt(this->unread_count);
	Writer.WriteInt(this->unread_mentions_count);
	this->notify_settings->OnSend(Writer);
	if(!this->pts)
	{
	Writer.WriteInt(this->pts);
	}
	if(!this->draft)
	{
	this->draft->OnSend(Writer);
	}
}


void Dialog::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 2)) != 0) 
	{
		pinned = true;
	}
	peer = reinterpret_cast<PRIVATE::Peer* >(Reader.TGReadObject());
	top_message = Reader.ReadInt();
	read_inbox_max_id = Reader.ReadInt();
	read_outbox_max_id = Reader.ReadInt();
	unread_count = Reader.ReadInt();
	unread_mentions_count = Reader.ReadInt();
	notify_settings = reinterpret_cast<COMMON::PeerNotifySettings* >(Reader.TGReadObject());
	if((Flags & (1 << 0)) != 0) 
	{
	pts = Reader.ReadInt();
	}
	if((Flags & (1 << 1)) != 0) 
	{
	draft = reinterpret_cast<COMMON::DraftMessage* >(Reader.TGReadObject());
	}
	this->_Responded = true;
}
Dialog::~Dialog()
{

}
}//end namespace block
