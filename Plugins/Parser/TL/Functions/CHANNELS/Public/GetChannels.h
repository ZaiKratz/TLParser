#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"
#include "../../../Types/Messages/Public/Chats.h"

//begin namespace block
namespace CHANNELS
{
class GetChannels : public TLBaseObject
{
public:
	GetChannels();
	GetChannels(TArray<COMMON::InputChannel*> id);

	~GetChannels();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<COMMON::InputChannel*> id;
	MESSAGES::Chats* result;
};
} //end namespace block
