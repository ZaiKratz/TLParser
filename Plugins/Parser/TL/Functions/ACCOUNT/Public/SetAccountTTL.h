#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/AccountDaysTTL.h"

//begin namespace block
namespace ACCOUNT
{
class SetAccountTTL : public TLBaseObject
{
public:
	SetAccountTTL();
	SetAccountTTL(COMMON::AccountDaysTTL* ttl);

	~SetAccountTTL();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::AccountDaysTTL* ttl;
	bool result;
};
} //end namespace block
