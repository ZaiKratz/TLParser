#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"

//begin namespace block
namespace CHANNELS
{
class CheckUsername : public TLBaseObject
{
public:
	CheckUsername();
	CheckUsername(COMMON::InputChannel* channel, FString username);

	~CheckUsername();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputChannel*  Getchannel() const
	{
		 return this->channel;
	}

	FString Getusername() const
	{
		 return this->username;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputChannel* channel;
	 FString username;
	bool result;
};
} //end namespace block
