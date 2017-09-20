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
private:
	COMMON::InputChannel* channel;
	 TArray<int32> id;
	MESSAGES::AffectedMessages* result;
};
} //end namespace block
