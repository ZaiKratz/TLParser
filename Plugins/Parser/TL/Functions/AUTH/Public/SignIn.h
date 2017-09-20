#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Auth/Public/Authorization.h"

//begin namespace block
namespace AUTH
{
class SignIn : public TLBaseObject
{
public:
	SignIn();
	SignIn(FString phone_number, FString phone_code_hash, FString phone_code);

	~SignIn();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString phone_number;
	 FString phone_code_hash;
	 FString phone_code;
	AUTH::Authorization* result;
};
} //end namespace block
