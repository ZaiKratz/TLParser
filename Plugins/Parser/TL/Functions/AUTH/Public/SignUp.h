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
private:
	FString phone_number;
	 FString phone_code_hash;
	 FString phone_code;
	 FString first_name;
	 FString last_name;
	AUTH::Authorization* result;
};
} //end namespace block
