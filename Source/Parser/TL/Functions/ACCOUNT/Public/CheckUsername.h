#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace ACCOUNT
{
class CheckUsername : public TLBaseObject
{
public:
	CheckUsername();
	CheckUsername(FString username);

	~CheckUsername();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getusername() const
	{
		 return this->username;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	FString username;
	bool result;
};
} //end namespace block
