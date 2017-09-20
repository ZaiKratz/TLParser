#include "../Public/ResendCode.h"


//begin namespace block
namespace AUTH
{

ResendCode::ResendCode()
{
	this->_ConstructorID = -1079381698;
	this->_ContentRelated = true;
}

ResendCode::ResendCode(FString phone_number, FString phone_code_hash)
{
	this->_ConstructorID = -1079381698;
	this->_ContentRelated = true;
	this->phone_number = phone_number;
	this->phone_code_hash = phone_code_hash;
}
void ResendCode::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->phone_number);
	Writer.TGWriteString(this->phone_code_hash);
}


void ResendCode::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<AUTH::SentCode*>(Reader.TGReadObject());
}
ResendCode::~ResendCode()
{

}
}//end namespace block
