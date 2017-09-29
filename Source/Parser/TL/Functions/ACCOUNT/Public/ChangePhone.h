#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace ACCOUNT
{
class ChangePhone : public TLBaseObject
{
public:
	ChangePhone();
	ChangePhone(FString phone_number, FString phone_code_hash, FString phone_code);

	~ChangePhone();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString GetPhoneNumber() const
	{
		 return this->phone_number;
	}

	FString GetPhoneCodeHash() const
	{
		 return this->phone_code_hash;
	}

	FString GetPhoneCode() const
	{
		 return this->phone_code;
	}

	COMMON::User* GetResult() const
	{
		 return this->result;
	}

private:
	FString phone_number;
	 FString phone_code_hash;
	 FString phone_code;
	COMMON::User* result;
};
} //end namespace block
