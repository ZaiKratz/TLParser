#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace ACCOUNT
{
class RegisterDevice : public TLBaseObject
{
public:
	RegisterDevice();
	RegisterDevice(int32 token_type, FString token);

	~RegisterDevice();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetTokenType() const
	{
		 return this->token_type;
	}

	FString Gettoken() const
	{
		 return this->token;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	int32 token_type;
	 FString token;
	bool result;
};
} //end namespace block
