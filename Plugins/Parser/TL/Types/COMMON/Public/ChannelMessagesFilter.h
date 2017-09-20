#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/MessageRange.h"

//begin namespace block
namespace COMMON
{
class ChannelMessagesFilter : public TLBaseObject
{
public:
	ChannelMessagesFilter();
	ChannelMessagesFilter(bool exclude_new_messages, TArray<COMMON::MessageRange*> ranges);

	~ChannelMessagesFilter();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool exclude_new_messages;
	 TArray<COMMON::MessageRange*> ranges;
};
} //end namespace block
