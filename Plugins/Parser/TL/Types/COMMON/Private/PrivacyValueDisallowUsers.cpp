#include "../Public/PrivacyValueDisallowUsers.h"


//begin namespace block
namespace COMMON
{

PrivacyValueDisallowUsers::PrivacyValueDisallowUsers()
{
	this->_ConstructorID = 64;
}

PrivacyValueDisallowUsers::PrivacyValueDisallowUsers(TArray<int32> users)
{
	this->_ConstructorID = 64;
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
	int32 Len23263 = Reader.ReadInt();
	for(int32 i = 0; i < Len23263; i++)
	{
	auto X = Reader.ReadInt();
	users.Add(X);
	}
}
PrivacyValueDisallowUsers::~PrivacyValueDisallowUsers()
{

}
}//end namespace block
