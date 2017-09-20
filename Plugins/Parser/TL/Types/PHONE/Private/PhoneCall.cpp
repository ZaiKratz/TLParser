#include "../Public/PhoneCall.h"


//begin namespace block
namespace PHONE
{

PhoneCall::PhoneCall()
{
	this->_ConstructorID = 1088520940;
}

PhoneCall::PhoneCall(COMMON::PhoneCall* phone_call, TArray<COMMON::User*> users)
{
	this->_ConstructorID = 1088520940;
	this->phone_call = phone_call;
	this->users = users;
}
void PhoneCall::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->phone_call->OnSend(Writer);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->users.Num());
	for(auto X : this->users)
	{
	X->OnSend(Writer);
	}
}


void PhoneCall::OnResponce(BinaryReader& Reader)
{
	phone_call = reinterpret_cast<COMMON::PhoneCall*>(Reader.TGReadObject());
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len9918 = Reader.ReadInt();
	for(int32 i = 0; i < Len9918; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
}
PhoneCall::~PhoneCall()
{

}
}//end namespace block
