#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UpdateReadChannelInbox : public TLBaseObject
{
public:
	UpdateReadChannelInbox();
	UpdateReadChannelInbox(int32 channel_id, int32 max_id);

	~UpdateReadChannelInbox();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetChannelId() const
	{
		 return this->channel_id;
	}

	int32 GetMaxId() const
	{
		 return this->max_id;
	}

private:
	int32 channel_id;
	 int32 max_id;
};
} //end namespace block
