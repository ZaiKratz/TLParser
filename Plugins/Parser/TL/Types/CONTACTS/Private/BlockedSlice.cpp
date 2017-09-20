#include "../Public/BlockedSlice.h"


//begin namespace block
namespace CONTACTS
{

BlockedSlice::BlockedSlice()
{
	this->_ConstructorID = -1593702256;
}

BlockedSlice::BlockedSlice(int32 count, TArray<COMMON::ContactBlocked*> blocked, TArray<COMMON::User*> users)
{
	this->_ConstructorID = -1593702256;
	this->count = count;
	this->blocked = blocked;
	this->users = users;
}
void BlockedSlice::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->count);
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


void BlockedSlice::OnResponce(BinaryReader& Reader)
{
	count = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len6974 = Reader.ReadInt();
	for(int32 i = 0; i < Len6974; i++)
	{
	auto X = reinterpret_cast<COMMON::ContactBlocked*>(Reader.TGReadObject());
	blocked.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len16248 = Reader.ReadInt();
	for(int32 i = 0; i < Len16248; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
}
BlockedSlice::~BlockedSlice()
{

}
}//end namespace block