#pragma once
#include "Engine.h"
#include "../../../Types/Private/PageBlock.h"

#include "../../../Types/Private/RichText.h"
#include "../../../Types/Private/PageBlock.h"

//begin namespace block
namespace COMMON
{
class PageBlockEmbed : public PRIVATE::PageBlock
{
public:
	PageBlockEmbed();
	PageBlockEmbed(bool full_width, bool allow_scrolling, FString url, FString html, unsigned long long poster_photo_id, int32 w, int32 h, PRIVATE::RichText* caption);

	~PageBlockEmbed();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool full_width;
	 bool allow_scrolling;
	 FString url;
	 FString html;
	 unsigned long long poster_photo_id;
	 int32 w;
	 int32 h;
	 PRIVATE::RichText* caption;
};
} //end namespace block
