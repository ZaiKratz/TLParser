#include "../Public/UpdatePrivacy.h"


//begin namespace block
namespace COMMON
{

UpdatePrivacy::UpdatePrivacy()
{
	this->_ConstructorID = -298113238;
}

UpdatePrivacy::UpdatePrivacy(PRIVATE::PrivacyKey*  key, TArray<PRIVATE::PrivacyRule*>  rules)
{
	this->_ConstructorID = -298113238;
	this->key = key;
	this->rules = rules;
}
void UpdatePrivacy::OnSend(BinaryWriter& Writer)
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


void UpdatePrivacy::OnResponce(BinaryReader& Reader)
{
	key = reinterpret_cast<PRIVATE::PrivacyKey* >(Reader.TGReadObject());
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len2633 = Reader.ReadInt();
	for(int32 i = 0; i < Len2633; i++)
	{
	auto X = reinterpret_cast<PRIVATE::PrivacyRule*>(Reader.TGReadObject());
	rules.Add(X);
	}
	this->_Responded = true;
}
UpdatePrivacy::~UpdatePrivacy()
{

}
}//end namespace block
