#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace PAYMENTS
{
class PaymentResult : public TLBaseObject
{
public:
	PaymentResult();
	PaymentResult(COMMON::Updates* updates);

	~PaymentResult();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::Updates*  Getupdates() const
	{
		 return this->updates;
	}

private:
	COMMON::Updates* updates;
};
} //end namespace block
