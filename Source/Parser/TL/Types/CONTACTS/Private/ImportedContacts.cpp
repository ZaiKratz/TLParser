#include "../Public/ImportedContacts.h"


//begin namespace block
namespace CONTACTS
{

ImportedContacts::ImportedContacts()
{
	this->_ConstructorID = 2010127419;
}

ImportedContacts::ImportedContacts(TArray<COMMON::ImportedContact*>  imported, TArray<COMMON::PopularContact*>  popular_invites, TArray<unsigned long long>  retry_contacts, TArray<COMMON::User*>  users)
{
	this->_ConstructorID = 2010127419;
	this->imported = imported;
	this->popular_invites = popular_invites;
	this->retry_contacts = retry_contacts;
	this->users = users;
}
void ImportedContacts::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->imported.Num());
	for(auto X : this->imported)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->popular_invites.Num());
	for(auto X : this->popular_invites)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->retry_contacts.Num());
	for(auto X : this->retry_contacts)
	{
	Writer.WriteLong(X);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->users.Num());
	for(auto X : this->users)
	{
	X->OnSend(Writer);
	}
}


void ImportedContacts::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len31345 = Reader.ReadInt();
	for(int32 i = 0; i < Len31345; i++)
	{
	auto X = reinterpret_cast<COMMON::ImportedContact*>(Reader.TGReadObject());
	imported.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len10717 = Reader.ReadInt();
	for(int32 i = 0; i < Len10717; i++)
	{
	auto X = reinterpret_cast<COMMON::PopularContact*>(Reader.TGReadObject());
	popular_invites.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len24239 = Reader.ReadInt();
	for(int32 i = 0; i < Len24239; i++)
	{
	auto X = Reader.ReadLong();
	retry_contacts.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len32232 = Reader.ReadInt();
	for(int32 i = 0; i < Len32232; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
	this->_Responded = true;
}
ImportedContacts::~ImportedContacts()
{
}
}//end namespace block
