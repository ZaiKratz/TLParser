#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/ChannelAdminLogEventAction.h"

//begin namespace block
namespace COMMON
{
class ChannelAdminLogEvent : public TLBaseObject
{
public:
	ChannelAdminLogEvent();
	ChannelAdminLogEvent(unsigned long long id, FDateTime date, int32 user_id, PRIVATE::ChannelAdminLogEventAction* action);

	~ChannelAdminLogEvent();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long Getid() const
	{
		 return this->id;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

	int32 GetUserId() const
	{
		 return this->user_id;
	}

	PRIVATE::ChannelAdminLogEventAction*  Getaction() const
	{
		 return this->action;
	}

private:
	unsigned long long id;
	 FDateTime date;
	 int32 user_id;
	 PRIVATE::ChannelAdminLogEventAction* action;
};
} //end namespace block
