#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ChannelMessagesFilter.h"

//begin namespace block
namespace COMMON
{
class ChannelMessagesFilterEmpty : public TLBaseObject
{
public:
	ChannelMessagesFilterEmpty();
	~ChannelMessagesFilterEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
