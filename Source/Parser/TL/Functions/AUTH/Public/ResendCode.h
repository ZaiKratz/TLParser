#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Auth/Public/SentCode.h"

//begin namespace block
namespace AUTH
{
class ResendCode : public TLBaseObject
{
public:
	ResendCode();
	ResendCode(FString phone_number, FString phone_code_hash);

	~ResendCode();
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

	AUTH::SentCode* GetResult() const
	{
		 return this->result;
	}

private:
	FString phone_number;
	 FString phone_code_hash;
	AUTH::SentCode* result;
};
} //end namespace block
