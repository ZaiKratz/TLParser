#pragma once
#include "Engine.h"
#include "../../../Types/Private/PageBlock.h"

#include "../../../Types/Private/PageBlock.h"
#include "../../../Types/Private/RichText.h"
#include "../../../Types/Private/PageBlock.h"

//begin namespace block
namespace COMMON
{
class PageBlockCollage : public PRIVATE::PageBlock
{
public:
	PageBlockCollage();
	PageBlockCollage(TArray<PRIVATE::PageBlock*> items, PRIVATE::RichText* caption);

	~PageBlockCollage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<PRIVATE::PageBlock*> items;
	 PRIVATE::RichText* caption;
};
} //end namespace block
