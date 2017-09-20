#include "../Public/Found.h"


//begin namespace block
namespace CONTACTS
{

Found::Found()
{
	this->_ConstructorID = -2064146150;
}

Found::Found(TArray<PRIVATE::Peer*> results, TArray<COMMON::Chat*> chats, TArray<COMMON::User*> users)
{
	this->_ConstructorID = -2064146150;
	this->results = results;
	this->chats = chats;
	this->users = users;
}
void Found::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->results.Num());
	for(auto X : this->results)
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


void Found::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len17516 = Reader.ReadInt();
	for(int32 i = 0; i < Len17516; i++)
	{
	auto X = reinterpret_cast<PRIVATE::Peer*>(Reader.TGReadObject());
	results.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len31870 = Reader.ReadInt();
	for(int32 i = 0; i < Len31870; i++)
	{
	auto X = reinterpret_cast<COMMON::Chat*>(Reader.TGReadObject());
	chats.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len86 = Reader.ReadInt();
	for(int32 i = 0; i < Len86; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
}
Found::~Found()
{

}
}//end namespace block
