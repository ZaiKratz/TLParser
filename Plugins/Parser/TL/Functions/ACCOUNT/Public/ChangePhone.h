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
private:
	FString phone_number;
	 FString phone_code_hash;
	 FString phone_code;
	COMMON::User* result;
};
} //end namespace block
