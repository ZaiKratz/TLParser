#include "../Public/PasswordSettings.h"


//begin namespace block
namespace ACCOUNT
{

PasswordSettings::PasswordSettings()
{
	this->_ConstructorID = -1289046089;
}

PasswordSettings::PasswordSettings(FString email)
{
	this->_ConstructorID = -1289046089;
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
}
PasswordSettings::~PasswordSettings()
{

}
}//end namespace block
