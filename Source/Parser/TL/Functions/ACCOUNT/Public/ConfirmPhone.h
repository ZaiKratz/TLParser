#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace ACCOUNT
{
class ConfirmPhone : public TLBaseObject
{
public:
	ConfirmPhone();
	ConfirmPhone(FString phone_code_hash, FString phone_code);

	~ConfirmPhone();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString GetPhoneCodeHash() const
	{
		 return this->phone_code_hash;
	}

	FString GetPhoneCode() const
	{
		 return this->phone_code;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	FString phone_code_hash;
	 FString phone_code;
	bool result;
};
} //end namespace block
