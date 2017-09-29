#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace ACCOUNT
{
class DeleteAccount : public TLBaseObject
{
public:
	DeleteAccount();
	DeleteAccount(FString reason);

	~DeleteAccount();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getreason() const
	{
		 return this->reason;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	FString reason;
	bool result;
};
} //end namespace block
