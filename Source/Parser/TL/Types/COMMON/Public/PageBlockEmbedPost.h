#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class PageBlockEmbedPost : public TLBaseObject
{
public:
	PageBlockEmbedPost();
	PageBlockEmbedPost(FString url, unsigned long long webpage_id, unsigned long long author_photo_id, FString author, FDateTime date, TArray<TLBaseObject*> blocks, TLBaseObject* caption);

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

	TArray<TLBaseObject*>  Getblocks() const
	{
		 return this->blocks;
	}

	TLBaseObject*  Getcaption() const
	{
		 return this->caption;
	}

private:
	FString url;
	 unsigned long long webpage_id;
	 unsigned long long author_photo_id;
	 FString author;
	 FDateTime date;
	 TArray<TLBaseObject*> blocks;
	 TLBaseObject* caption;
};
} //end namespace block
