#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class NearestDc : public TLBaseObject
{
public:
	NearestDc();
	NearestDc(FString country, int32 this_dc, int32 nearest_dc);

	~NearestDc();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getcountry() const
	{
		 return this->country;
	}

	int32 GetThisDc() const
	{
		 return this->this_dc;
	}

	int32 GetNearestDc() const
	{
		 return this->nearest_dc;
	}

private:
	FString country;
	 int32 this_dc;
	 int32 nearest_dc;
};
} //end namespace block
