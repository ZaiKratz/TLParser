#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Auth/Public/Authorization.h"

//begin namespace block
namespace AUTH
{
class SignUp : public TLBaseObject
{
public:
	SignUp();
	SignUp(FString phone_number, FString phone_code_hash, FString phone_code, FString first_name, FString last_name);

	~SignUp();
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

	FString GetFirstName() const
	{
		 return this->first_name;
	}

	FString GetLastName() const
	{
		 return this->last_name;
	}

	AUTH::Authorization* GetResult() const
	{
		 return this->result;
	}

private:
	FString phone_number;
	 FString phone_code_hash;
	 FString phone_code;
	 FString first_name;
	 FString last_name;
	AUTH::Authorization* result;
};
} //end namespace block
