#include "../Public/Blocked.h"


//begin namespace block
namespace CONTACTS
{

Blocked::Blocked()
{
	this->_ConstructorID = 361567004;
}

Blocked::Blocked(TArray<COMMON::ContactBlocked*> blocked, TArray<COMMON::User*> users)
{
	this->_ConstructorID = 361567004;
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
	int32 Len6793 = Reader.ReadInt();
	for(int32 i = 0; i < Len6793; i++)
	{
	auto X = reinterpret_cast<COMMON::ContactBlocked*>(Reader.TGReadObject());
	blocked.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len13702 = Reader.ReadInt();
	for(int32 i = 0; i < Len13702; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
}
Blocked::~Blocked()
{

}
}//end namespace block
