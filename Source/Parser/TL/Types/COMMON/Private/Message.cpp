#include "../Public/Message.h"


//begin namespace block
namespace COMMON
{

Message::Message()
{
	this->_ConstructorID = -1864508399;
}

Message::Message(bool out, bool mentioned, bool media_unread, bool silent, bool post, int32 id, int32 from_id, TLBaseObject*  to_id, COMMON::MessageFwdHeader*  fwd_from, int32 via_bot_id, int32 reply_to_msg_id, FDateTime date, FString message, TLBaseObject*  media, TLBaseObject*  reply_markup, TArray<TLBaseObject*>  entities, int32 views, FDateTime edit_date, FString post_author)
{
	this->_ConstructorID = -1864508399;
	this->out = out;
	this->mentioned = mentioned;
	this->media_unread = media_unread;
	this->silent = silent;
	this->post = post;
	this->id = id;
	this->from_id = from_id;
	this->to_id = to_id;
	this->fwd_from = fwd_from;
	this->via_bot_id = via_bot_id;
	this->reply_to_msg_id = reply_to_msg_id;
	this->date = date;
	this->message = message;
	this->media = media;
	this->reply_markup = reply_markup;
	this->entities = entities;
	this->views = views;
	this->edit_date = edit_date;
	this->post_author = post_author;
}
void Message::OnSend(BinaryWriter& Writer)
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
	if(post)
	{
		Flags |= (1 << 14);
	}
	else
	{
		Flags |= 0;
	}
	if(from_id)
	{
		Flags |= (1 << 8);
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
	if(media)
	{
		Flags |= (1 << 9);
	}
	else
	{
		Flags |= 0;
	}
	if(reply_markup)
	{
		Flags |= (1 << 6);
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
	if(views)
	{
		Flags |= (1 << 10);
	}
	else
	{
		Flags |= 0;
	}
	if(edit_date == FDateTime::MinValue())
	{
		Flags |= (1 << 15);
	}
	else
	{
		Flags |= 0;
	}
	if(!post_author.IsEmpty())
	{
		Flags |= (1 << 16);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->id);
	if(this->from_id)
	{
	Writer.WriteInt(this->from_id);
	}
	this->to_id->OnSend(Writer);
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
	Writer.TGWriteDate(this->date);
	Writer.TGWriteString(this->message);
	if(this->media)
	{
	this->media->OnSend(Writer);
	}
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
	if(this->views)
	{
	Writer.WriteInt(this->views);
	}
	if(edit_date == FDateTime::MinValue())
	{
	Writer.TGWriteDate(this->edit_date);
	}
	Writer.TGWriteString(this->post_author);
}


void Message::OnResponce(BinaryReader& Reader)
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
	if((Flags & (1 << 14)) != 0) 
	{
		post = true;
	}
	id = Reader.ReadInt();
	if((Flags & (1 << 8)) != 0) 
	{
	from_id = Reader.ReadInt();
	}
	to_id = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
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
	date = Reader.TGReadDate();
	message = Reader.TGReadString();
	if((Flags & (1 << 9)) != 0) 
	{
	media = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	}
	if((Flags & (1 << 6)) != 0) 
	{
	reply_markup = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	}
	if((Flags & (1 << 7)) != 0) 
	{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len18817 = Reader.ReadInt();
	for(int32 i = 0; i < Len18817; i++)
	{
	auto X = reinterpret_cast<TLBaseObject*>(Reader.TGReadObject());
	entities.Add(X);
	}
	}
	if((Flags & (1 << 10)) != 0) 
	{
	views = Reader.ReadInt();
	}
	if((Flags & (1 << 15)) != 0) 
	{
	edit_date = Reader.TGReadDate();
	}
	if((Flags & (1 << 16)) != 0) 
	{
	post_author = Reader.TGReadString();
	}
	this->_Responded = true;
}
Message::~Message()
{
	if(this->to_id)
	{
		delete this->to_id;
	}
	if(this->fwd_from)
	{
		delete this->fwd_from;
	}
	if(this->media)
	{
		delete this->media;
	}
	if(this->reply_markup)
	{
		delete this->reply_markup;
	}
}
}//end namespace block
