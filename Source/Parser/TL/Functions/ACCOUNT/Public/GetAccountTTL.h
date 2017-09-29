#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/AccountDaysTTL.h"

//begin namespace block
namespace ACCOUNT
{
class GetAccountTTL : public TLBaseObject
{
public:
	GetAccountTTL();
	~GetAccountTTL();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::AccountDaysTTL* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::AccountDaysTTL* result;
};
} //end namespace block
