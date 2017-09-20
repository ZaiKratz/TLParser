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
private:
	FString reason;
	bool result;
};
} //end namespace block
