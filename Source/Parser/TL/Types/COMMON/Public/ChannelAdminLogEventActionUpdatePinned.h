#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Message.h"

//begin namespace block
namespace COMMON
{
class ChannelAdminLogEventActionUpdatePinned : public TLBaseObject
{
public:
	ChannelAdminLogEventActionUpdatePinned();
	ChannelAdminLogEventActionUpdatePinned(COMMON::Message* message);

	~ChannelAdminLogEventActionUpdatePinned();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::Message*  Getmessage() const
	{
		 return this->message;
	}

private:
	COMMON::Message* message;
};
} //end namespace block
