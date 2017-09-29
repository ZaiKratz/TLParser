#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"
#include "../../../Types/Common/Public/InputUser.h"

//begin namespace block
namespace CHANNELS
{
class ReportSpam : public TLBaseObject
{
public:
	ReportSpam();
	ReportSpam(COMMON::InputChannel* channel, COMMON::InputUser* user_id, TArray<int32> id);

	~ReportSpam();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputChannel*  Getchannel() const
	{
		 return this->channel;
	}

	COMMON::InputUser*  GetUserId() const
	{
		 return this->user_id;
	}

	TArray<int32>  Getid() const
	{
		 return this->id;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputChannel* channel;
	 COMMON::InputUser* user_id;
	 TArray<int32> id;
	bool result;
};
} //end namespace block
