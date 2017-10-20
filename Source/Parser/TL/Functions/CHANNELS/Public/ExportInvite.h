#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"

//begin namespace block
namespace CHANNELS
{
class ExportInvite : public TLBaseObject
{
public:
	ExportInvite();
	ExportInvite(COMMON::InputChannel* channel);

	~ExportInvite();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputChannel*  Getchannel() const
	{
		 return this->channel;
	}

	TLBaseObject* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputChannel* channel;
	TLBaseObject* result;
};
} //end namespace block
