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

	TArray<uint8>  GetCurrentPasswordHash() const
	{
		 return this->current_password_hash;
	}

	ACCOUNT::PasswordInputSettings*  GetNewSettings() const
	{
		 return this->new_settings;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	TArray<uint8> current_password_hash;
	 ACCOUNT::PasswordInputSettings* new_settings;
	bool result;
};
} //end namespace block
