#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class PageBlockEmbed : public TLBaseObject
{
public:
	PageBlockEmbed();
	PageBlockEmbed(bool full_width, bool allow_scrolling, FString url, FString html, unsigned long long poster_photo_id, int32 w, int32 h, TLBaseObject* caption);

	~PageBlockEmbed();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetFullWidth() const
	{
		 return this->full_width;
	}

	bool GetAllowScrolling() const
	{
		 return this->allow_scrolling;
	}

	FString Geturl() const
	{
		 return this->url;
	}

	FString Gethtml() const
	{
		 return this->html;
	}

	unsigned long long GetPosterPhotoId() const
	{
		 return this->poster_photo_id;
	}

	int32 Getw() const
	{
		 return this->w;
	}

	int32 Geth() const
	{
		 return this->h;
	}

	TLBaseObject*  Getcaption() const
	{
		 return this->caption;
	}

private:
	bool full_width;
	 bool allow_scrolling;
	 FString url;
	 FString html;
	 unsigned long long poster_photo_id;
	 int32 w;
	 int32 h;
	 TLBaseObject* caption;
};
} //end namespace block
