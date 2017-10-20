#include "../Public/NoPassword.h"


//begin namespace block
namespace ACCOUNT
{

NoPassword::NoPassword()
{
	this->_ConstructorID = -1764049896;
}

NoPassword::NoPassword(TArray<uint8>  new_salt, FString email_unconfirmed_pattern)
{
	this->_ConstructorID = -1764049896;
	this->new_salt = new_salt;
	this->email_unconfirmed_pattern = email_unconfirmed_pattern;
}
void NoPassword::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteBytes((unsigned char*)this->new_salt.GetData(), this->new_salt.Num());
	Writer.TGWriteString(this->email_unconfirmed_pattern);
}


void NoPassword::OnResponce(BinaryReader& Reader)
{
	new_salt = Reader.TGReadBytes();
	email_unconfirmed_pattern = Reader.TGReadString();
	this->_Responded = true;
}
NoPassword::~NoPassword()
{
}
}//end namespace block
