#include "../Public/MessagesSlice.h"


//begin namespace block
namespace MESSAGES
{

MessagesSlice::MessagesSlice()
{
	this->_ConstructorID = 189033187;
}

MessagesSlice::MessagesSlice(int32 count, TArray<COMMON::Message*>  messages, TArray<COMMON::Chat*>  chats, TArray<COMMON::User*>  users)
{
	this->_ConstructorID = 189033187;
	this->count = count;
	this->messages = messages;
	this->chats = chats;
	this->users = users;
}
void MessagesSlice::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
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


void MessagesSlice::OnResponce(BinaryReader& Reader)
{
	count = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len8310 = Reader.ReadInt();
	for(int32 i = 0; i < Len8310; i++)
	{
	auto X = reinterpret_cast<COMMON::Message*>(Reader.TGReadObject());
	messages.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len17328 = Reader.ReadInt();
	for(int32 i = 0; i < Len17328; i++)
	{
	auto X = reinterpret_cast<COMMON::Chat*>(Reader.TGReadObject());
	chats.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len8687 = Reader.ReadInt();
	for(int32 i = 0; i < Len8687; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
	this->_Responded = true;
}
MessagesSlice::~MessagesSlice()
{

}
}//end namespace block
