#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class MsgsStateReq : public TLBaseObject
{
public:
	MsgsStateReq();
	MsgsStateReq(TArray<unsigned long long> msg_ids);

	~MsgsStateReq();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<unsigned long long> msg_ids;
};
} //end namespace block
