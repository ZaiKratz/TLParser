#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace ACCOUNT
{
class Password : public TLBaseObject
{
public:
	Password();
	Password(TArray<uint8> current_salt, TArray<uint8> new_salt, FString hint, bool has_recovery, FString email_unconfirmed_pattern);

	~Password();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<uint8>  GetCurrentSalt() const
	{
		 return this->current_salt;
	}

	TArray<uint8>  GetNewSalt() const
	{
		 return this->new_salt;
	}

	FString Gethint() const
	{
		 return this->hint;
	}

	bool GetHasRecovery() const
	{
		 return this->has_recovery;
	}

	FString GetEmailUnconfirmedPattern() const
	{
		 return this->email_unconfirmed_pattern;
	}

private:
	TArray<uint8> current_salt;
	 TArray<uint8> new_salt;
	 FString hint;
	 bool has_recovery;
	 FString email_unconfirmed_pattern;
};
} //end namespace block
