#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/ACCOUNT/Public/PasswordInputSettings.h"

//begin namespace block
namespace ACCOUNT
{
class UpdatePasswordSettings : public TLBaseObject
{
public:
	UpdatePasswordSettings();
	UpdatePasswordSettings(TArray<uint8> current_password_hash, ACCOUNT::PasswordInputSettings* new_settings);

	~UpdatePasswordSettings();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<uint8> current_password_hash;
	 ACCOUNT::PasswordInputSettings* new_settings;
	bool result;
};
} //end namespace block
