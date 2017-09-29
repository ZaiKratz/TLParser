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

	TArray<COMMON::InputChannel*>  Getid() const
	{
		 return this->id;
	}

	MESSAGES::Chats* GetResult() const
	{
		 return this->result;
	}

private:
	TArray<COMMON::InputChannel*> id;
	MESSAGES::Chats* result;
};
} //end namespace block
