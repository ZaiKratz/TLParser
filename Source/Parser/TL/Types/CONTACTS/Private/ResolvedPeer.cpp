#include "../Public/ResolvedPeer.h"


//begin namespace block
namespace CONTACTS
{

ResolvedPeer::ResolvedPeer()
{
	this->_ConstructorID = 2131196633;
}

ResolvedPeer::ResolvedPeer(TLBaseObject*  peer, TArray<COMMON::Chat*>  chats, TArray<COMMON::User*>  users)
{
	this->_ConstructorID = 2131196633;
	this->peer = peer;
	this->chats = chats;
	this->users = users;
}
void ResolvedPeer::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
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


void ResolvedPeer::OnResponce(BinaryReader& Reader)
{
	peer = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len8513 = Reader.ReadInt();
	for(int32 i = 0; i < Len8513; i++)
	{
	auto X = reinterpret_cast<COMMON::Chat*>(Reader.TGReadObject());
	chats.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len14764 = Reader.ReadInt();
	for(int32 i = 0; i < Len14764; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
	this->_Responded = true;
}
ResolvedPeer::~ResolvedPeer()
{
	if(this->peer)
	{
		delete this->peer;
	}
}
}//end namespace block
