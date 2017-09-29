#include "../Public/ChatFull.h"


//begin namespace block
namespace MESSAGES
{

ChatFull::ChatFull()
{
	this->_ConstructorID = -438840932;
}

ChatFull::ChatFull(COMMON::ChatFull*  full_chat, TArray<COMMON::Chat*>  chats, TArray<COMMON::User*>  users)
{
	this->_ConstructorID = -438840932;
	this->full_chat = full_chat;
	this->chats = chats;
	this->users = users;
}
void ChatFull::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->full_chat->OnSend(Writer);
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


void ChatFull::OnResponce(BinaryReader& Reader)
{
	full_chat = reinterpret_cast<COMMON::ChatFull* >(Reader.TGReadObject());
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len27888 = Reader.ReadInt();
	for(int32 i = 0; i < Len27888; i++)
	{
	auto X = reinterpret_cast<COMMON::Chat*>(Reader.TGReadObject());
	chats.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len32747 = Reader.ReadInt();
	for(int32 i = 0; i < Len32747; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
	this->_Responded = true;
}
ChatFull::~ChatFull()
{

}
}//end namespace block
