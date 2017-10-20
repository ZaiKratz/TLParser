#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputPeerChannel : public TLBaseObject
{
public:
	InputPeerChannel();
	InputPeerChannel(int32 channel_id, unsigned long long access_hash);

	~InputPeerChannel();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetChannelId() const
	{
		 return this->channel_id;
	}

	unsigned long long GetAccessHash() const
	{
		 return this->access_hash;
	}

private:
	int32 channel_id;
	 unsigned long long access_hash;
};
} //end namespace block
