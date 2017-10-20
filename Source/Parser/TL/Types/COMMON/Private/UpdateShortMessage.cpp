#include "../Public/UpdateShortMessage.h"


//begin namespace block
namespace COMMON
{

UpdateShortMessage::UpdateShortMessage()
{
	this->_ConstructorID = -1857044719;
}

UpdateShortMessage::UpdateShortMessage(bool out, bool mentioned, bool media_unread, bool silent, int32 id, int32 user_id, FString message, int32 pts, int32 pts_count, FDateTime date, COMMON::MessageFwdHeader*  fwd_from, int32 via_bot_id, int32 reply_to_msg_id, TArray<TLBaseObject*>  entities)
{
	this->_ConstructorID = -1857044719;
	this->out = out;
	this->mentioned = mentioned;
	this->media_unread = media_unread;
	this->silent = silent;
	this->id = id;
	this->user_id = user_id;
	this->message = message;
	this->pts = pts;
	this->pts_count = pts_count;
	this->date = date;
	this->fwd_from = fwd_from;
	this->via_bot_id = via_bot_id;
	this->reply_to_msg_id = reply_to_msg_id;
	this->entities = entities;
}
void UpdateShortMessage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(out)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(mentioned)
	{
		Flags |= (1 << 4);
	}
	else
	{
		Flags |= 0;
	}
	if(media_unread)
	{
		Flags |= (1 << 5);
	}
	else
	{
		Flags |= 0;
	}
	if(silent)
	{
		Flags |= (1 << 13);
	}
	else
	{
		Flags |= 0;
	}
	if(fwd_from)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(via_bot_id)
	{
		Flags |= (1 << 11);
	}
	else
	{
		Flags |= 0;
	}
	if(reply_to_msg_id)
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	if(entities.Num())
	{
		Flags |= (1 << 7);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->id);
	Writer.WriteInt(this->user_id);
	Writer.TGWriteString(this->message);
	Writer.WriteInt(this->pts);
	Writer.WriteInt(this->pts_count);
	Writer.TGWriteDate(this->date);
	if(this->fwd_from)
	{
	this->fwd_from->OnSend(Writer);
	}
	if(this->via_bot_id)
	{
	Writer.WriteInt(this->via_bot_id);
	}
	if(this->reply_to_msg_id)
	{
	Writer.WriteInt(this->reply_to_msg_id);
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


void UpdateShortMessage::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 1)) != 0) 
	{
		out = true;
	}
	if((Flags & (1 << 4)) != 0) 
	{
		mentioned = true;
	}
	if((Flags & (1 << 5)) != 0) 
	{
		media_unread = true;
	}
	if((Flags & (1 << 13)) != 0) 
	{
		silent = true;
	}
	id = Reader.ReadInt();
	user_id = Reader.ReadInt();
	message = Reader.TGReadString();
	pts = Reader.ReadInt();
	pts_count = Reader.ReadInt();
	date = Reader.TGReadDate();
	if((Flags & (1 << 2)) != 0) 
	{
	fwd_from = reinterpret_cast<COMMON::MessageFwdHeader* >(Reader.TGReadObject());
	}
	if((Flags & (1 << 11)) != 0) 
	{
	via_bot_id = Reader.ReadInt();
	}
	if((Flags & (1 << 3)) != 0) 
	{
	reply_to_msg_id = Reader.ReadInt();
	}
	if((Flags & (1 << 7)) != 0) 
	{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len27222 = Reader.ReadInt();
	for(int32 i = 0; i < Len27222; i++)
	{
	auto X = reinterpret_cast<TLBaseObject*>(Reader.TGReadObject());
	entities.Add(X);
	}
	}
	this->_Responded = true;
}
UpdateShortMessage::~UpdateShortMessage()
{
	if(this->fwd_from)
	{
		delete this->fwd_from;
	}
}
}//end namespace block
