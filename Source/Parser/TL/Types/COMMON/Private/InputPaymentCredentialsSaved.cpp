#include "../Public/InputPaymentCredentialsSaved.h"


//begin namespace block
namespace COMMON
{

InputPaymentCredentialsSaved::InputPaymentCredentialsSaved()
{
	this->_ConstructorID = -1056001329;
}

InputPaymentCredentialsSaved::InputPaymentCredentialsSaved(FString id, TArray<uint8>  tmp_password)
{
	this->_ConstructorID = -1056001329;
	this->id = id;
	this->tmp_password = tmp_password;
}
void InputPaymentCredentialsSaved::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->id);
	Writer.TGWriteBytes((unsigned char*)this->tmp_password.GetData(), this->tmp_password.Num());
}


void InputPaymentCredentialsSaved::OnResponce(BinaryReader& Reader)
{
	id = Reader.TGReadString();
	tmp_password = Reader.TGReadBytes();
	this->_Responded = true;
}
InputPaymentCredentialsSaved::~InputPaymentCredentialsSaved()
{

}
}//end namespace block
