#include "../Public/PrivacyValueAllowUsers.h"


//begin namespace block
namespace COMMON
{

PrivacyValueAllowUsers::PrivacyValueAllowUsers()
{
	this->_ConstructorID = 1297858060;
}

PrivacyValueAllowUsers::PrivacyValueAllowUsers(TArray<int32>  users)
{
	this->_ConstructorID = 1297858060;
	this->users = users;
}
void PrivacyValueAllowUsers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->users.Num());
	for(auto X : this->users)
	{
	Writer.WriteInt(X);
	}
}


void PrivacyValueAllowUsers::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len1033 = Reader.ReadInt();
	for(int32 i = 0; i < Len1033; i++)
	{
	auto X = Reader.ReadInt();
	users.Add(X);
	}
	this->_Responded = true;
}
PrivacyValueAllowUsers::~PrivacyValueAllowUsers()
{
}
}//end namespace block
