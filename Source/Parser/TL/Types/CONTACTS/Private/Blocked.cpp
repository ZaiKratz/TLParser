#include "../Public/Blocked.h"


//begin namespace block
namespace CONTACTS
{

Blocked::Blocked()
{
	this->_ConstructorID = 471043349;
}

Blocked::Blocked(TArray<COMMON::ContactBlocked*>  blocked, TArray<COMMON::User*>  users)
{
	this->_ConstructorID = 471043349;
	this->blocked = blocked;
	this->users = users;
}
void Blocked::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->blocked.Num());
	for(auto X : this->blocked)
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


void Blocked::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len21038 = Reader.ReadInt();
	for(int32 i = 0; i < Len21038; i++)
	{
	auto X = reinterpret_cast<COMMON::ContactBlocked*>(Reader.TGReadObject());
	blocked.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len27718 = Reader.ReadInt();
	for(int32 i = 0; i < Len27718; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
	this->_Responded = true;
}
Blocked::~Blocked()
{

}
}//end namespace block
