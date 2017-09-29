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

	TArray<unsigned long long>  GetMsgIds() const
	{
		 return this->msg_ids;
	}

	FString Getinfo() const
	{
		 return this->info;
	}

private:
	TArray<unsigned long long> msg_ids;
	 FString info;
};
} //end namespace block
