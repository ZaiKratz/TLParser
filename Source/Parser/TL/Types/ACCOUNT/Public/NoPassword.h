#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Account/Public/Password.h"

//begin namespace block
namespace ACCOUNT
{
class NoPassword : public TLBaseObject
{
public:
	NoPassword();
	NoPassword(TArray<uint8> new_salt, FString email_unconfirmed_pattern);

	~NoPassword();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<uint8>  GetNewSalt() const
	{
		 return this->new_salt;
	}

	FString GetEmailUnconfirmedPattern() const
	{
		 return this->email_unconfirmed_pattern;
	}

private:
	TArray<uint8> new_salt;
	 FString email_unconfirmed_pattern;
};
} //end namespace block
