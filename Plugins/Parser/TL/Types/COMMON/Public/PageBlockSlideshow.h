#pragma once
#include "Engine.h"
#include "../../../Types/Private/PageBlock.h"

#include "../../../Types/Private/PageBlock.h"
#include "../../../Types/Private/RichText.h"
#include "../../../Types/Private/PageBlock.h"

//begin namespace block
namespace COMMON
{
class PageBlockSlideshow : public PRIVATE::PageBlock
{
public:
	PageBlockSlideshow();
	PageBlockSlideshow(TArray<PRIVATE::PageBlock*> items, PRIVATE::RichText* caption);

	~PageBlockSlideshow();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<PRIVATE::PageBlock*> items;
	 PRIVATE::RichText* caption;
};
} //end namespace block
