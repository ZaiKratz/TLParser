#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Photo.h"
#include "../../../Types/Common/Public/Document.h"

//begin namespace block
namespace COMMON
{
class WebPage : public TLBaseObject
{
public:
	WebPage();
	WebPage(unsigned long long id, FString url, FString display_url, int32 hash, FString type, FString site_name, FString title, FString description, COMMON::Photo* photo, FString embed_url, FString embed_type, int32 embed_width, int32 embed_height, int32 duration, FString author, COMMON::Document* document, TLBaseObject* cached_page);

	~WebPage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long Getid() const
	{
		 return this->id;
	}

	FString Geturl() const
	{
		 return this->url;
	}

	FString GetDisplayUrl() const
	{
		 return this->display_url;
	}

	int32 Gethash() const
	{
		 return this->hash;
	}

	FString Gettype() const
	{
		 return this->type;
	}

	FString GetSiteName() const
	{
		 return this->site_name;
	}

	FString Gettitle() const
	{
		 return this->title;
	}

	FString Getdescription() const
	{
		 return this->description;
	}

	COMMON::Photo*  Getphoto() const
	{
		 return this->photo;
	}

	FString GetEmbedUrl() const
	{
		 return this->embed_url;
	}

	FString GetEmbedType() const
	{
		 return this->embed_type;
	}

	int32 GetEmbedWidth() const
	{
		 return this->embed_width;
	}

	int32 GetEmbedHeight() const
	{
		 return this->embed_height;
	}

	int32 Getduration() const
	{
		 return this->duration;
	}

	FString Getauthor() const
	{
		 return this->author;
	}

	COMMON::Document*  Getdocument() const
	{
		 return this->document;
	}

	TLBaseObject*  GetCachedPage() const
	{
		 return this->cached_page;
	}

private:
	unsigned long long id;
	 FString url;
	 FString display_url;
	 int32 hash;
	 FString type;
	 FString site_name;
	 FString title;
	 FString description;
	 COMMON::Photo* photo;
	 FString embed_url;
	 FString embed_type;
	 int32 embed_width;
	 int32 embed_height;
	 int32 duration;
	 FString author;
	 COMMON::Document* document;
	 TLBaseObject* cached_page;
};
} //end namespace block
