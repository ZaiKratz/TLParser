#include "../Public/SetPrivacy.h"


//begin namespace block
namespace ACCOUNT
{

SetPrivacy::SetPrivacy()
{
	this->_ConstructorID = -906486552;
	this->_ContentRelated = true;
}

SetPrivacy::SetPrivacy(PRIVATE::InputPrivacyKey*  key, TArray<PRIVATE::InputPrivacyRule*>  rules)
{
	this->_ConstructorID = -906486552;
	this->_ContentRelated = true;
	this->key = key;
	this->rules = rules;
}
void SetPrivacy::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->key->OnSend(Writer);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->rules.Num());
	for(auto X : this->rules)
	{
	X->OnSend(Writer);
	}
}


void SetPrivacy::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<ACCOUNT::PrivacyRules*>(Reader.TGReadObject());
	this->_Responded = true;
}
SetPrivacy::~SetPrivacy()
{

}
}//end namespace block
