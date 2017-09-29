#include "../Public/PrivacyRules.h"


//begin namespace block
namespace ACCOUNT
{

PrivacyRules::PrivacyRules()
{
	this->_ConstructorID = 1430961007;
}

PrivacyRules::PrivacyRules(TArray<PRIVATE::PrivacyRule*>  rules, TArray<COMMON::User*>  users)
{
	this->_ConstructorID = 1430961007;
	this->rules = rules;
	this->users = users;
}
void PrivacyRules::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->rules.Num());
	for(auto X : this->rules)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->users.Num());
	for(auto X : this->users)
	{
	X->OnSend(Writer);
	}
}


void PrivacyRules::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len28386 = Reader.ReadInt();
	for(int32 i = 0; i < Len28386; i++)
	{
	auto X = reinterpret_cast<PRIVATE::PrivacyRule*>(Reader.TGReadObject());
	rules.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len13394 = Reader.ReadInt();
	for(int32 i = 0; i < Len13394; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
	this->_Responded = true;
}
PrivacyRules::~PrivacyRules()
{

}
}//end namespace block
