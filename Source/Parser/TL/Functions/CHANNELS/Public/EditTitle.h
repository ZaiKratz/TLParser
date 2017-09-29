#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace CHANNELS
{
class EditTitle : public TLBaseObject
{
public:
	EditTitle();
	EditTitle(COMMON::InputChannel* channel, FString title);

	~EditTitle();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputChannel*  Getchannel() const
	{
		 return this->channel;
	}

	FString Gettitle() const
	{
		 return this->title;
	}

	COMMON::Updates* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputChannel* channel;
	 FString title;
	COMMON::Updates* result;
};
} //end namespace block
