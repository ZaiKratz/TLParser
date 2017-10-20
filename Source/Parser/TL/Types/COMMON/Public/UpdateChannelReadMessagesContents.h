#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UpdateChannelReadMessagesContents : public TLBaseObject
{
public:
	UpdateChannelReadMessagesContents();
	UpdateChannelReadMessagesContents(int32 channel_id, TArray<int32> messages);

	~UpdateChannelReadMessagesContents();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetChannelId() const
	{
		 return this->channel_id;
	}

	TArray<int32>  Getmessages() const
	{
		 return this->messages;
	}

private:
	int32 channel_id;
	 TArray<int32> messages;
};
} //end namespace block
