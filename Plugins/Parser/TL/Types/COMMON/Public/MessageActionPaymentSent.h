#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageAction.h"

#include "../../../Types/Private/MessageAction.h"

//begin namespace block
namespace COMMON
{
class MessageActionPaymentSent : public PRIVATE::MessageAction
{
public:
	MessageActionPaymentSent();
	MessageActionPaymentSent(FString currency, unsigned long long total_amount);

	~MessageActionPaymentSent();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString currency;
	 unsigned long long total_amount;
};
} //end namespace block
