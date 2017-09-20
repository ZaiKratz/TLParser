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
private:
	FString country;
	 int32 this_dc;
	 int32 nearest_dc;
};
} //end namespace block
