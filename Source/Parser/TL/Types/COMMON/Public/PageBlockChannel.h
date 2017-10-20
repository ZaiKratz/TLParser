#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Chat.h"

//begin namespace block
namespace COMMON
{
class PageBlockChannel : public TLBaseObject
{
public:
	PageBlockChannel();
	PageBlockChannel(COMMON::Chat* channel);

	~PageBlockChannel();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::Chat*  Getchannel() const
	{
		 return this->channel;
	}

private:
	COMMON::Chat* channel;
};
} //end namespace block
