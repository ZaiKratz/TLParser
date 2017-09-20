#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ShippingOption.h"

//begin namespace block
namespace MESSAGES
{
class SetBotShippingResults : public TLBaseObject
{
public:
	SetBotShippingResults();
	SetBotShippingResults(unsigned long long query_id, FString error, TArray<COMMON::ShippingOption*> shipping_options);

	~SetBotShippingResults();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long query_id;
	 FString error;
	 TArray<COMMON::ShippingOption*> shipping_options;
	bool result;
};
} //end namespace block
