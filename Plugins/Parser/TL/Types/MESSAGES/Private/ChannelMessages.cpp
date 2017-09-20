#include "../Public/ChannelMessages.h"


//begin namespace block
namespace MESSAGES
{

ChannelMessages::ChannelMessages()
{
	this->_ConstructorID = 925771417;
}

ChannelMessages::ChannelMessages(int32 pts, int32 count, TArray<COMMON::Message*> messages, TArray<COMMON::Chat*> chats, TArray<COMMON::User*> users)
{
	this->_ConstructorID = 925771417;
	this->pts = pts;
	this->count = count;
	this->messages = messages;
	this->chats = chats;
	this->users = users;
}
void ChannelMessages::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->pts);
	Writer.WriteInt(this->count);
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


void ChannelMessages::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	pts = Reader.ReadInt();
	count = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len26081 = Reader.ReadInt();
	for(int32 i = 0; i < Len26081; i++)
	{
	auto X = reinterpret_cast<COMMON::Message*>(Reader.TGReadObject());
	messages.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len19519 = Reader.ReadInt();
	for(int32 i = 0; i < Len19519; i++)
	{
	auto X = reinterpret_cast<COMMON::Chat*>(Reader.TGReadObject());
	chats.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len1781 = Reader.ReadInt();
	for(int32 i = 0; i < Len1781; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
}
ChannelMessages::~ChannelMessages()
{

}
}//end namespace block
