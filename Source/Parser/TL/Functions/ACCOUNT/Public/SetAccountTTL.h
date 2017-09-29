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

	COMMON::AccountDaysTTL*  Getttl() const
	{
		 return this->ttl;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::AccountDaysTTL* ttl;
	bool result;
};
} //end namespace block
