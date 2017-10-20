#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UpdateChannel : public TLBaseObject
{
public:
	UpdateChannel();
	UpdateChannel(int32 channel_id);

	~UpdateChannel();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetChannelId() const
	{
		 return this->channel_id;
	}

private:
	int32 channel_id;
};
} //end namespace block
