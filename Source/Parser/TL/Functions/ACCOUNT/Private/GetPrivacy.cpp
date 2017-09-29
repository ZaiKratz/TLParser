#include "../Public/GetPrivacy.h"


//begin namespace block
namespace ACCOUNT
{

GetPrivacy::GetPrivacy()
{
	this->_ConstructorID = -623130288;
	this->_ContentRelated = true;
}

GetPrivacy::GetPrivacy(PRIVATE::InputPrivacyKey*  key)
{
	this->_ConstructorID = -623130288;
	this->_ContentRelated = true;
	this->key = key;
}
void GetPrivacy::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->key->OnSend(Writer);
}


void GetPrivacy::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<ACCOUNT::PrivacyRules*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetPrivacy::~GetPrivacy()
{

}
}//end namespace block
