#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Auth/Public/Authorization.h"

//begin namespace block
namespace AUTH
{
class RecoverPassword : public TLBaseObject
{
public:
	RecoverPassword();
	RecoverPassword(FString code);

	~RecoverPassword();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getcode() const
	{
		 return this->code;
	}

	AUTH::Authorization* GetResult() const
	{
		 return this->result;
	}

private:
	FString code;
	AUTH::Authorization* result;
};
} //end namespace block
