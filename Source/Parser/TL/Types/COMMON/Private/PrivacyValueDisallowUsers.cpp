#include "../Public/PrivacyValueDisallowUsers.h"


//begin namespace block
namespace COMMON
{

PrivacyValueDisallowUsers::PrivacyValueDisallowUsers()
{
	this->_ConstructorID = 209668535;
}

PrivacyValueDisallowUsers::PrivacyValueDisallowUsers(TArray<int32>  users)
{
	this->_ConstructorID = 209668535;
	this->users = users;
}
void PrivacyValueDisallowUsers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->users.Num());
	for(auto X : this->users)
	{
	Writer.WriteInt(X);
	}
}


void PrivacyValueDisallowUsers::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len30013 = Reader.ReadInt();
	for(int32 i = 0; i < Len30013; i++)
	{
	auto X = Reader.ReadInt();
	users.Add(X);
	}
	this->_Responded = true;
}
PrivacyValueDisallowUsers::~PrivacyValueDisallowUsers()
{
}
}//end namespace block
