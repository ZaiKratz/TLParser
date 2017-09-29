#include "../Public/TopPeers.h"


//begin namespace block
namespace CONTACTS
{

TopPeers::TopPeers()
{
	this->_ConstructorID = 1891070632;
}

TopPeers::TopPeers(TArray<COMMON::TopPeerCategoryPeers*>  categories, TArray<COMMON::Chat*>  chats, TArray<COMMON::User*>  users)
{
	this->_ConstructorID = 1891070632;
	this->categories = categories;
	this->chats = chats;
	this->users = users;
}
void TopPeers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->categories.Num());
	for(auto X : this->categories)
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


void TopPeers::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len14924 = Reader.ReadInt();
	for(int32 i = 0; i < Len14924; i++)
	{
	auto X = reinterpret_cast<COMMON::TopPeerCategoryPeers*>(Reader.TGReadObject());
	categories.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len12852 = Reader.ReadInt();
	for(int32 i = 0; i < Len12852; i++)
	{
	auto X = reinterpret_cast<COMMON::Chat*>(Reader.TGReadObject());
	chats.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len22262 = Reader.ReadInt();
	for(int32 i = 0; i < Len22262; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
	this->_Responded = true;
}
TopPeers::~TopPeers()
{

}
}//end namespace block
