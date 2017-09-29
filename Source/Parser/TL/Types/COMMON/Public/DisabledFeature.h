#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class DisabledFeature : public TLBaseObject
{
public:
	DisabledFeature();
	DisabledFeature(FString feature, FString description);

	~DisabledFeature();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getfeature() const
	{
		 return this->feature;
	}

	FString Getdescription() const
	{
		 return this->description;
	}

private:
	FString feature;
	 FString description;
};
} //end namespace block
