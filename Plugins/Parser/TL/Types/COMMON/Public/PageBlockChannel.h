#pragma once
#include "Engine.h"
#include "../../../Types/Private/PageBlock.h"

#include "../../../Types/Common/Public/Chat.h"
#include "../../../Types/Private/PageBlock.h"

//begin namespace block
namespace COMMON
{
class PageBlockChannel : public PRIVATE::PageBlock
{
public:
	PageBlockChannel();
	PageBlockChannel(COMMON::Chat* channel);

	~PageBlockChannel();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::Chat* channel;
};
} //end namespace block
