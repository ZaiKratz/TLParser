#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class FutureSalt : public TLBaseObject
{
public:
	FutureSalt();
	FutureSalt(int32 valid_since, int32 valid_until, unsigned long long salt);

	~FutureSalt();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 valid_since;
	 int32 valid_until;
	 unsigned long long salt;
};
} //end namespace block
