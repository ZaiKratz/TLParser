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

	bool Getautoplay() const
	{
		 return this->autoplay;
	}

	bool Getloop() const
	{
		 return this->loop;
	}

	unsigned long long GetVideoId() const
	{
		 return this->video_id;
	}

	PRIVATE::RichText*  Getcaption() const
	{
		 return this->caption;
	}

private:
	bool autoplay;
	 bool loop;
	 unsigned long long video_id;
	 PRIVATE::RichText* caption;
};
} //end namespace block
