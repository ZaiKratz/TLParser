#include "../Public/CancelCode.h"


//begin namespace block
namespace AUTH
{

CancelCode::CancelCode()
{
	this->_ConstructorID = 520357240;
	this->_ContentRelated = true;
}

CancelCode::CancelCode(FString phone_number, FString phone_code_hash)
{
	this->_ConstructorID = 520357240;
	this->_ContentRelated = true;
	this->phone_number = phone_number;
	this->phone_code_hash = phone_code_hash;
}
void CancelCode::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->phone_number);
	Writer.TGWriteString(this->phone_code_hash);
}


void CancelCode::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
CancelCode::~CancelCode()
{

}
}//end namespace block
