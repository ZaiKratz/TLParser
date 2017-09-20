#pragma once
#include "Engine.h"
#include "../../../Types/Private/Page.h"

#include "../../../Types/Private/PageBlock.h"
#include "../../../Types/Common/Public/Photo.h"
#include "../../../Types/Common/Public/Document.h"
#include "../../../Types/Private/Page.h"

//begin namespace block
namespace COMMON
{
class PagePart : public PRIVATE::Page
{
public:
	PagePart();
	PagePart(TArray<PRIVATE::PageBlock*> blocks, TArray<COMMON::Photo*> photos, TArray<COMMON::Document*> documents);

	~PagePart();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<PRIVATE::PageBlock*> blocks;
	 TArray<COMMON::Photo*> photos;
	 TArray<COMMON::Document*> documents;
};
} //end namespace block