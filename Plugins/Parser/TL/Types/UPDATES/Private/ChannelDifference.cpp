#include "../Public/ChannelDifference.h"


//begin namespace block
namespace UPDATES
{

ChannelDifference::ChannelDifference()
{
	this->_ConstructorID = 1315398688;
}

ChannelDifference::ChannelDifference(bool final, int32 pts, int32 timeout, TArray<COMMON::Message*> new_messages, TArray<PRIVATE::Update*> other_updates, TArray<COMMON::Chat*> chats, TArray<COMMON::User*> users)
{
	this->_ConstructorID = 1315398688;
	this->final = final;
	this->pts = pts;
	this->timeout = timeout;
	this->new_messages = new_messages;
	this->other_updates = other_updates;
	this->chats = chats;
	this->users = users;
}
void ChannelDifference::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!final)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!timeout)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->pts);
	if(!this->timeout)
	{
	Writer.WriteInt(this->timeout);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->new_messages.Num());
	for(auto X : this->new_messages)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->other_updates.Num());
	for(auto X : this->other_updates)
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


void ChannelDifference::OnResponce(BinaryReader& Reader)
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
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len5884 = Reader.ReadInt();
	for(int32 i = 0; i < Len5884; i++)
	{
	auto X = reinterpret_cast<COMMON::Message*>(Reader.TGReadObject());
	new_messages.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len29304 = Reader.ReadInt();
	for(int32 i = 0; i < Len29304; i++)
	{
	auto X = reinterpret_cast<PRIVATE::Update*>(Reader.TGReadObject());
	other_updates.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len5341 = Reader.ReadInt();
	for(int32 i = 0; i < Len5341; i++)
	{
	auto X = reinterpret_cast<COMMON::Chat*>(Reader.TGReadObject());
	chats.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len11089 = Reader.ReadInt();
	for(int32 i = 0; i < Len11089; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
}
ChannelDifference::~ChannelDifference()
{

}
}//end namespace block
