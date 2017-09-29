#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"

//begin namespace block
namespace CHANNELS
{
class EditAbout : public TLBaseObject
{
public:
	EditAbout();
	EditAbout(COMMON::InputChannel* channel, FString about);

	~EditAbout();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputChannel*  Getchannel() const
	{
		 return this->channel;
	}

	FString Getabout() const
	{
		 return this->about;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputChannel* channel;
	 FString about;
	bool result;
};
} //end namespace block
