#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"

//begin namespace block
namespace CHANNELS
{
class SetStickers : public TLBaseObject
{
public:
	SetStickers();
	SetStickers(COMMON::InputChannel* channel, TLBaseObject* stickerset);

	~SetStickers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputChannel*  Getchannel() const
	{
		 return this->channel;
	}

	TLBaseObject*  Getstickerset() const
	{
		 return this->stickerset;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputChannel* channel;
	 TLBaseObject* stickerset;
	bool result;
};
} //end namespace block
