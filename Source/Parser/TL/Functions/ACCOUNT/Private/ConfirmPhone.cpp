#include "../Public/ConfirmPhone.h"


//begin namespace block
namespace ACCOUNT
{

ConfirmPhone::ConfirmPhone()
{
	this->_ConstructorID = 1596029123;
	this->_ContentRelated = true;
}

ConfirmPhone::ConfirmPhone(FString phone_code_hash, FString phone_code)
{
	this->_ConstructorID = 1596029123;
	this->_ContentRelated = true;
	this->phone_code_hash = phone_code_hash;
	this->phone_code = phone_code;
}
void ConfirmPhone::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->phone_code_hash);
	Writer.TGWriteString(this->phone_code);
}


void ConfirmPhone::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
ConfirmPhone::~ConfirmPhone()
{

}
}//end namespace block
