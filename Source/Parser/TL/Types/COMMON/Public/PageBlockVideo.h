#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class PageBlockVideo : public TLBaseObject
{
public:
	PageBlockVideo();
	PageBlockVideo(bool autoplay, bool loop, unsigned long long video_id, TLBaseObject* caption);

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

	TLBaseObject*  Getcaption() const
	{
		 return this->caption;
	}

private:
	bool autoplay;
	 bool loop;
	 unsigned long long video_id;
	 TLBaseObject* caption;
};
} //end namespace block
