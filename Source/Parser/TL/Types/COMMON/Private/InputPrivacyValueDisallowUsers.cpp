#include "../Public/InputPrivacyValueDisallowUsers.h"


//begin namespace block
namespace COMMON
{

InputPrivacyValueDisallowUsers::InputPrivacyValueDisallowUsers()
{
	this->_ConstructorID = -1877932953;
}

InputPrivacyValueDisallowUsers::InputPrivacyValueDisallowUsers(TArray<COMMON::InputUser*>  users)
{
	this->_ConstructorID = -1877932953;
	this->users = users;
}
void InputPrivacyValueDisallowUsers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->users.Num());
	for(auto X : this->users)
	{
	X->OnSend(Writer);
	}
}


void InputPrivacyValueDisallowUsers::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len7275 = Reader.ReadInt();
	for(int32 i = 0; i < Len7275; i++)
	{
	auto X = reinterpret_cast<COMMON::InputUser*>(Reader.TGReadObject());
	users.Add(X);
	}
	this->_Responded = true;
}
InputPrivacyValueDisallowUsers::~InputPrivacyValueDisallowUsers()
{
}
}//end namespace block
