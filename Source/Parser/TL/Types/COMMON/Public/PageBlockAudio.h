#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class PageBlockAudio : public TLBaseObject
{
public:
	PageBlockAudio();
	PageBlockAudio(unsigned long long audio_id, TLBaseObject* caption);

	~PageBlockAudio();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetAudioId() const
	{
		 return this->audio_id;
	}

	TLBaseObject*  Getcaption() const
	{
		 return this->caption;
	}

private:
	unsigned long long audio_id;
	 TLBaseObject* caption;
};
} //end namespace block
