#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace ACCOUNT
{
class PasswordSettings : public TLBaseObject
{
public:
	PasswordSettings();
	PasswordSettings(FString email);

	~PasswordSettings();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString email;
};
} //end namespace block
