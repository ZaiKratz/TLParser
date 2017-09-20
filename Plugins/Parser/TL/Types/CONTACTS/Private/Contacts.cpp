#include "../Public/Contacts.h"


//begin namespace block
namespace CONTACTS
{

Contacts::Contacts()
{
	this->_ConstructorID = 1115613418;
}

Contacts::Contacts(TArray<COMMON::Contact*> contacts, int32 saved_count, TArray<COMMON::User*> users)
{
	this->_ConstructorID = 1115613418;
	this->contacts = contacts;
	this->saved_count = saved_count;
	this->users = users;
}
void Contacts::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->contacts.Num());
	for(auto X : this->contacts)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(this->saved_count);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->users.Num());
	for(auto X : this->users)
	{
	X->OnSend(Writer);
	}
}


void Contacts::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len8953 = Reader.ReadInt();
	for(int32 i = 0; i < Len8953; i++)
	{
	auto X = reinterpret_cast<COMMON::Contact*>(Reader.TGReadObject());
	contacts.Add(X);
	}
	saved_count = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len24998 = Reader.ReadInt();
	for(int32 i = 0; i < Len24998; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
}
Contacts::~Contacts()
{

}
}//end namespace block