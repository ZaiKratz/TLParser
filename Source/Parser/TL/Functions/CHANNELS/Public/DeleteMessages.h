#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"
#include "../../../Types/Messages/Public/AffectedMessages.h"

//begin namespace block
namespace CHANNELS
{
class DeleteMessages : public TLBaseObject
{
public:
	DeleteMessages();
	DeleteMessages(COMMON::InputChannel* channel, TArray<int32> id);

	~DeleteMessages();
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

	MESSAGES::AffectedMessages* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputChannel* channel;
	 TArray<int32> id;
	MESSAGES::AffectedMessages* result;
};
} //end namespace block
