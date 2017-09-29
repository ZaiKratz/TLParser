#include "../Public/ChangePhone.h"


//begin namespace block
namespace ACCOUNT
{

ChangePhone::ChangePhone()
{
	this->_ConstructorID = 1891839707;
	this->_ContentRelated = true;
}

ChangePhone::ChangePhone(FString phone_number, FString phone_code_hash, FString phone_code)
{
	this->_ConstructorID = 1891839707;
	this->_ContentRelated = true;
	this->phone_number = phone_number;
	this->phone_code_hash = phone_code_hash;
	this->phone_code = phone_code;
}
void ChangePhone::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->phone_number);
	Writer.TGWriteString(this->phone_code_hash);
	Writer.TGWriteString(this->phone_code);
}


void ChangePhone::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	this->_Responded = true;
}
ChangePhone::~ChangePhone()
{

}
}//end namespace block
