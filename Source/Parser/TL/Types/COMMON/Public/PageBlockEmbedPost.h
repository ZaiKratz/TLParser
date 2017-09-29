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

	FString Geturl() const
	{
		 return this->url;
	}

	unsigned long long GetWebpageId() const
	{
		 return this->webpage_id;
	}

	unsigned long long GetAuthorPhotoId() const
	{
		 return this->author_photo_id;
	}

	FString Getauthor() const
	{
		 return this->author;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

	TArray<PRIVATE::PageBlock*>  Getblocks() const
	{
		 return this->blocks;
	}

	PRIVATE::RichText*  Getcaption() const
	{
		 return this->caption;
	}

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
