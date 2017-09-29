#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"
#include "../../../Types/Messages/Public/Messages.h"

//begin namespace block
namespace CHANNELS
{
class GetMessages : public TLBaseObject
{
public:
	GetMessages();
	GetMessages(COMMON::InputChannel* channel, TArray<int32> id);

	~GetMessages();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputChannel*  Getchannel() const
	{
		 return this->channel;
	}

	TArray<int32>  Getid() const
	{
		 return this->id;
	}

	MESSAGES::Messages* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputChannel* channel;
	 TArray<int32> id;
	MESSAGES::Messages* result;
};
} //end namespace block
