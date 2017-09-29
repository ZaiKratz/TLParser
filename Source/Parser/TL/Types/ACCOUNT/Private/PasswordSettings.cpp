#include "../Public/PasswordSettings.h"


//begin namespace block
namespace ACCOUNT
{

PasswordSettings::PasswordSettings()
{
	this->_ConstructorID = -1212732749;
}

PasswordSettings::PasswordSettings(FString email)
{
	this->_ConstructorID = -1212732749;
	this->email = email;
}
void PasswordSettings::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->email);
}


void PasswordSettings::OnResponce(BinaryReader& Reader)
{
	email = Reader.TGReadString();
	this->_Responded = true;
}
PasswordSettings::~PasswordSettings()
{

}
}//end namespace block
