#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ReceivedNotifyMessage.h"

//begin namespace block
namespace MESSAGES
{
class ReceivedMessages : public TLBaseObject
{
public:
	ReceivedMessages();
	ReceivedMessages(int32 max_id);

	~ReceivedMessages();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetMaxId() const
	{
		 return this->max_id;
	}

	TArray<COMMON::ReceivedNotifyMessage*> GetResult() const
	{
		 return this->result;
	}

private:
	int32 max_id;
	TArray<COMMON::ReceivedNotifyMessage*> result;
};
} //end namespace block
