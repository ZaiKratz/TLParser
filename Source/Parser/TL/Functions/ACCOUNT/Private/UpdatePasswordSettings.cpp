#include "../Public/UpdatePasswordSettings.h"


//begin namespace block
namespace ACCOUNT
{

UpdatePasswordSettings::UpdatePasswordSettings()
{
	this->_ConstructorID = -92517498;
	this->_ContentRelated = true;
}

UpdatePasswordSettings::UpdatePasswordSettings(TArray<uint8>  current_password_hash, ACCOUNT::PasswordInputSettings*  new_settings)
{
	this->_ConstructorID = -92517498;
	this->_ContentRelated = true;
	this->current_password_hash = current_password_hash;
	this->new_settings = new_settings;
}
void UpdatePasswordSettings::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteBytes((unsigned char*)this->current_password_hash.GetData(), this->current_password_hash.Num());
	this->new_settings->OnSend(Writer);
}


void UpdatePasswordSettings::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
UpdatePasswordSettings::~UpdatePasswordSettings()
{

}
}//end namespace block
