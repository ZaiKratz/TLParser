#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Message.h"

//begin namespace block
namespace COMMON
{
class UpdateNewChannelMessage : public TLBaseObject
{
public:
	UpdateNewChannelMessage();
	UpdateNewChannelMessage(COMMON::Message* message, int32 pts, int32 pts_count);

	~UpdateNewChannelMessage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::Message*  Getmessage() const
	{
		 return this->message;
	}

	int32 Getpts() const
	{
		 return this->pts;
	}

	int32 GetPtsCount() const
	{
		 return this->pts_count;
	}

private:
	COMMON::Message* message;
	 int32 pts;
	 int32 pts_count;
};
} //end namespace block
