#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Account/Public/PasswordSettings.h"

//begin namespace block
namespace ACCOUNT
{
class GetPasswordSettings : public TLBaseObject
{
public:
	GetPasswordSettings();
	GetPasswordSettings(TArray<uint8> current_password_hash);

	~GetPasswordSettings();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<uint8> current_password_hash;
	ACCOUNT::PasswordSettings* result;
};
} //end namespace block
