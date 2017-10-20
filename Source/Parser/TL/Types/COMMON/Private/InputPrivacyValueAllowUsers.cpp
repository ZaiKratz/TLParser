#include "../Public/InputPrivacyValueAllowUsers.h"


//begin namespace block
namespace COMMON
{

InputPrivacyValueAllowUsers::InputPrivacyValueAllowUsers()
{
	this->_ConstructorID = 320652927;
}

InputPrivacyValueAllowUsers::InputPrivacyValueAllowUsers(TArray<COMMON::InputUser*>  users)
{
	this->_ConstructorID = 320652927;
	this->users = users;
}
void InputPrivacyValueAllowUsers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->users.Num());
	for(auto X : this->users)
	{
	X->OnSend(Writer);
	}
}


void InputPrivacyValueAllowUsers::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len27434 = Reader.ReadInt();
	for(int32 i = 0; i < Len27434; i++)
	{
	auto X = reinterpret_cast<COMMON::InputUser*>(Reader.TGReadObject());
	users.Add(X);
	}
	this->_Responded = true;
}
InputPrivacyValueAllowUsers::~InputPrivacyValueAllowUsers()
{
}
}//end namespace block
