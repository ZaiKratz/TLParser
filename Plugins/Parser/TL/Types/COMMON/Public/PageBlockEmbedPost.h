#pragma once
#include "Engine.h"
#include "../../../Types/Private/PageBlock.h"

#include "../../../Types/Private/PageBlock.h"
#include "../../../Types/Private/RichText.h"
#include "../../../Types/Private/PageBlock.h"

//begin namespace block
namespace COMMON
{
class PageBlockEmbedPost : public PRIVATE::PageBlock
{
public:
	PageBlockEmbedPost();
	PageBlockEmbedPost(FString url, unsigned long long webpage_id, unsigned long long author_photo_id, FString author, FDateTime date, TArray<PRIVATE::PageBlock*> blocks, PRIVATE::RichText* caption);

	~PageBlockEmbedPost();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString url;
	 unsigned long long webpage_id;
	 unsigned long long author_photo_id;
	 FString author;
	 FDateTime date;
	 TArray<PRIVATE::PageBlock*> blocks;
	 PRIVATE::RichText* caption;
};
} //end namespace block
