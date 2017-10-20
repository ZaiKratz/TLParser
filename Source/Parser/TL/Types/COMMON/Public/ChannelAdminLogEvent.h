#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class ChannelAdminLogEvent : public TLBaseObject
{
public:
	ChannelAdminLogEvent();
	ChannelAdminLogEvent(unsigned long long id, FDateTime date, int32 user_id, TLBaseObject* action);

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

	TLBaseObject*  Getaction() const
	{
		 return this->action;
	}

private:
	unsigned long long id;
	 FDateTime date;
	 int32 user_id;
	 TLBaseObject* action;
};
} //end namespace block
