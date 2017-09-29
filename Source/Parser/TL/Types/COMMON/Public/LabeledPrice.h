#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class LabeledPrice : public TLBaseObject
{
public:
	LabeledPrice();
	LabeledPrice(FString label, unsigned long long amount);

	~LabeledPrice();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getlabel() const
	{
		 return this->label;
	}

	unsigned long long Getamount() const
	{
		 return this->amount;
	}

private:
	FString label;
	 unsigned long long amount;
};
} //end namespace block
