#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Photo.h"
#include "../../../Types/Common/Public/Document.h"
#include "../../../Types/Private/Page.h"

//begin namespace block
namespace COMMON
{
class WebPage : public TLBaseObject
{
public:
	WebPage();
	WebPage(unsigned long long id, FString url, FString display_url, int32 hash, FString type, FString site_name, FString title, FString description, COMMON::Photo* photo, FString embed_url, FString embed_type, int32 embed_width, int32 embed_height, int32 duration, FString author, COMMON::Document* document, PRIVATE::Page* cached_page);

	~WebPage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
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
	 PRIVATE::Page* cached_page;
};
} //end namespace block
