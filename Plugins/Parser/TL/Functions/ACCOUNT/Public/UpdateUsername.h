#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace ACCOUNT
{
class UpdateUsername : public TLBaseObject
{
public:
	UpdateUsername();
	UpdateUsername(FString username);

	~UpdateUsername();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString username;
	COMMON::User* result;
};
} //end namespace block
