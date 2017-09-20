#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace ACCOUNT
{
class PasswordInputSettings : public TLBaseObject
{
public:
	PasswordInputSettings();
	PasswordInputSettings(TArray<uint8> new_salt, TArray<uint8> new_password_hash, FString hint, FString email);

	~PasswordInputSettings();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<uint8> new_salt;
	 TArray<uint8> new_password_hash;
	 FString hint;
	 FString email;
};
} //end namespace block
