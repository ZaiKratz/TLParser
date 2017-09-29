#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"
#include "../../../Types/Common/Public/ExportedMessageLink.h"

//begin namespace block
namespace CHANNELS
{
class ExportMessageLink : public TLBaseObject
{
public:
	ExportMessageLink();
	ExportMessageLink(COMMON::InputChannel* channel, int32 id);

	~ExportMessageLink();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputChannel*  Getchannel() const
	{
		 return this->channel;
	}

	int32 Getid() const
	{
		 return this->id;
	}

	COMMON::ExportedMessageLink* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputChannel* channel;
	 int32 id;
	COMMON::ExportedMessageLink* result;
};
} //end namespace block
