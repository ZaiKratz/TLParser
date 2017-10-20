#include "../Public/ChannelDifferenceTooLong.h"


//begin namespace block
namespace UPDATES
{

ChannelDifferenceTooLong::ChannelDifferenceTooLong()
{
	this->_ConstructorID = 1788705589;
}

ChannelDifferenceTooLong::ChannelDifferenceTooLong(bool final, int32 pts, int32 timeout, int32 top_message, int32 read_inbox_max_id, int32 read_outbox_max_id, int32 unread_count, int32 unread_mentions_count, TArray<COMMON::Message*>  messages, TArray<COMMON::Chat*>  chats, TArray<COMMON::User*>  users)
{
	this->_ConstructorID = 1788705589;
	this->final = final;
	this->pts = pts;
	this->timeout = timeout;
	this->top_message = top_message;
	this->read_inbox_max_id = read_inbox_max_id;
	this->read_outbox_max_id = read_outbox_max_id;
	this->unread_count = unread_count;
	this->unread_mentions_count = unread_mentions_count;
	this->messages = messages;
	this->chats = chats;
	this->users = users;
}
void ChannelDifferenceTooLong::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(final)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(timeout)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->pts);
	if(this->timeout)
	{
	Writer.WriteInt(this->timeout);
	}
	Writer.WriteInt(this->top_message);
	Writer.WriteInt(this->read_inbox_max_id);
	Writer.WriteInt(this->read_outbox_max_id);
	Writer.WriteInt(this->unread_count);
	Writer.WriteInt(this->unread_mentions_count);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->messages.Num());
	for(auto X : this->messages)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->chats.Num());
	for(auto X : this->chats)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->users.Num());
	for(auto X : this->users)
	{
	X->OnSend(Writer);
	}
}


void ChannelDifferenceTooLong::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		final = true;
	}
	pts = Reader.ReadInt();
	if((Flags & (1 << 1)) != 0) 
	{
	timeout = Reader.ReadInt();
	}
	top_message = Reader.ReadInt();
	read_inbox_max_id = Reader.ReadInt();
	read_outbox_max_id = Reader.ReadInt();
	unread_count = Reader.ReadInt();
	unread_mentions_count = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len11494 = Reader.ReadInt();
	for(int32 i = 0; i < Len11494; i++)
	{
	auto X = reinterpret_cast<COMMON::Message*>(Reader.TGReadObject());
	messages.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len31550 = Reader.ReadInt();
	for(int32 i = 0; i < Len31550; i++)
	{
	auto X = reinterpret_cast<COMMON::Chat*>(Reader.TGReadObject());
	chats.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len16339 = Reader.ReadInt();
	for(int32 i = 0; i < Len16339; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
	this->_Responded = true;
}
ChannelDifferenceTooLong::~ChannelDifferenceTooLong()
{
}
}//end namespace block
