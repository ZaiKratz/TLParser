#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class MsgsStateInfo : public TLBaseObject
{
public:
	MsgsStateInfo();
	MsgsStateInfo(unsigned long long req_msg_id, FString info);

	~MsgsStateInfo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetReqMsgId() const
	{
		 return this->req_msg_id;
	}

	FString Getinfo() const
	{
		 return this->info;
	}

private:
	unsigned long long req_msg_id;
	 FString info;
};
} //end namespace block
