#include "../Public/GetPasswordSettings.h"


//begin namespace block
namespace ACCOUNT
{

GetPasswordSettings::GetPasswordSettings()
{
	this->_ConstructorID = -1131605573;
	this->_ContentRelated = true;
}

GetPasswordSettings::GetPasswordSettings(TArray<uint8>  current_password_hash)
{
	this->_ConstructorID = -1131605573;
	this->_ContentRelated = true;
	this->current_password_hash = current_password_hash;
}
void GetPasswordSettings::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteBytes((unsigned char*)this->current_password_hash.GetData(), this->current_password_hash.Num());
}


void GetPasswordSettings::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<ACCOUNT::PasswordSettings*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetPasswordSettings::~GetPasswordSettings()
{

}
}//end namespace block
