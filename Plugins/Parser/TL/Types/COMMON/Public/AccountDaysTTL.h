#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class AccountDaysTTL : public TLBaseObject
{
public:
	AccountDaysTTL();
	AccountDaysTTL(int32 days);

	~AccountDaysTTL();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 days;
};
} //end namespace block
