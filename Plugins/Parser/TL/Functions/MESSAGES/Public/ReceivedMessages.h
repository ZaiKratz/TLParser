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
private:
	int32 max_id;
	TArray<COMMON::ReceivedNotifyMessage*> result;
};
} //end namespace block
