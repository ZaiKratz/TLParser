#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class MsgsAllInfo : public TLBaseObject
{
public:
	MsgsAllInfo();
	MsgsAllInfo(TArray<unsigned long long> msg_ids, FString info);

	~MsgsAllInfo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<unsigned long long> msg_ids;
	 FString info;
};
} //end namespace block
