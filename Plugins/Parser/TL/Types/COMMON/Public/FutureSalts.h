#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/FutureSalt.h"

//begin namespace block
namespace COMMON
{
class FutureSalts : public TLBaseObject
{
public:
	FutureSalts();
	FutureSalts(unsigned long long req_msg_id, int32 now, TArray<COMMON::FutureSalt*> salts);

	~FutureSalts();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long req_msg_id;
	 int32 now;
	 TArray<COMMON::FutureSalt*> salts;
};
} //end namespace block
