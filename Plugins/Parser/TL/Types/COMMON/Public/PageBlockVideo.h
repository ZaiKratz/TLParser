#pragma once
#include "Engine.h"
#include "../../../Types/Private/PageBlock.h"

#include "../../../Types/Private/RichText.h"
#include "../../../Types/Private/PageBlock.h"

//begin namespace block
namespace COMMON
{
class PageBlockVideo : public PRIVATE::PageBlock
{
public:
	PageBlockVideo();
	PageBlockVideo(bool autoplay, bool loop, unsigned long long video_id, PRIVATE::RichText* caption);

	~PageBlockVideo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool autoplay;
	 bool loop;
	 unsigned long long video_id;
	 PRIVATE::RichText* caption;
};
} //end namespace block
