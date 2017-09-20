#pragma once
#include "Engine.h"
#include "../../../Types/Private/PageBlock.h"

#include "../../../Types/Private/RichText.h"
#include "../../../Types/Private/PageBlock.h"

//begin namespace block
namespace COMMON
{
class PageBlockAudio : public PRIVATE::PageBlock
{
public:
	PageBlockAudio();
	PageBlockAudio(unsigned long long audio_id, PRIVATE::RichText* caption);

	~PageBlockAudio();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long audio_id;
	 PRIVATE::RichText* caption;
};
} //end namespace block
