#include "../Public/MessageService.h"


//begin namespace block
namespace COMMON
{

MessageService::MessageService()
{
	this->_ConstructorID = -1642487306;
}

MessageService::MessageService(bool out, bool mentioned, bool media_unread, bool silent, bool post, int32 id, int32 from_id, PRIVATE::Peer*  to_id, int32 reply_to_msg_id, FDateTime date, PRIVATE::MessageAction*  action)
{
	this->_ConstructorID = -1642487306;
	this->out = out;
	this->mentioned = mentioned;
	this->media_unread = media_unread;
	this->silent = silent;
	this->post = post;
	this->id = id;
	this->from_id = from_id;
	this->to_id = to_id;
	this->reply_to_msg_id = reply_to_msg_id;
	this->date = date;
	this->action = action;
}
void MessageService::OnSend(BinaryWriter& Writer)
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
	if(reply_to_msg_id)
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->id);
	if(!this->from_id)
	{
	Writer.WriteInt(this->from_id);
	}
	this->to_id->OnSend(Writer);
	if(!this->reply_to_msg_id)
	{
	Writer.WriteInt(this->reply_to_msg_id);
	}
	Writer.TGWriteDate(this->date);
	this->action->OnSend(Writer);
}


void MessageService::OnResponce(BinaryReader& Reader)
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
	to_id = reinterpret_cast<PRIVATE::Peer* >(Reader.TGReadObject());
	if((Flags & (1 << 3)) != 0) 
	{
	reply_to_msg_id = Reader.ReadInt();
	}
	date = Reader.TGReadDate();
	action = reinterpret_cast<PRIVATE::MessageAction* >(Reader.TGReadObject());
	this->_Responded = true;
}
MessageService::~MessageService()
{

}
}//end namespace block
