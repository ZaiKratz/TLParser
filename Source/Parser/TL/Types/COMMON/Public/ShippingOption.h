#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/LabeledPrice.h"

//begin namespace block
namespace COMMON
{
class ShippingOption : public TLBaseObject
{
public:
	ShippingOption();
	ShippingOption(FString id, FString title, TArray<COMMON::LabeledPrice*> prices);

	~ShippingOption();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getid() const
	{
		 return this->id;
	}

	FString Gettitle() const
	{
		 return this->title;
	}

	TArray<COMMON::LabeledPrice*>  Getprices() const
	{
		 return this->prices;
	}

private:
	FString id;
	 FString title;
	 TArray<COMMON::LabeledPrice*> prices;
};
} //end namespace block
