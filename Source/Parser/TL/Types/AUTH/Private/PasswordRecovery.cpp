#include "../Public/PasswordRecovery.h"


//begin namespace block
namespace AUTH
{

PasswordRecovery::PasswordRecovery()
{
	this->_ConstructorID = 326715557;
}

PasswordRecovery::PasswordRecovery(FString email_pattern)
{
	this->_ConstructorID = 326715557;
	this->email_pattern = email_pattern;
}
void PasswordRecovery::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->email_pattern);
}


void PasswordRecovery::OnResponce(BinaryReader& Reader)
{
	email_pattern = Reader.TGReadString();
	this->_Responded = true;
}
PasswordRecovery::~PasswordRecovery()
{

}
}//end namespace block
