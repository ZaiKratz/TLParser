#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/LabeledPrice.h"

//begin namespace block
namespace COMMON
{
class Invoice : public TLBaseObject
{
public:
	Invoice();
	Invoice(bool test, bool name_requested, bool phone_requested, bool email_requested, bool shipping_address_requested, bool flexible, FString currency, TArray<COMMON::LabeledPrice*> prices);

	~Invoice();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool test;
	 bool name_requested;
	 bool phone_requested;
	 bool email_requested;
	 bool shipping_address_requested;
	 bool flexible;
	 FString currency;
	 TArray<COMMON::LabeledPrice*> prices;
};
} //end namespace block
