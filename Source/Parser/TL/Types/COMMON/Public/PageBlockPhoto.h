#pragma once
#include "Engine.h"
#include "../../../Types/Private/PageBlock.h"

#include "../../../Types/Private/RichText.h"
#include "../../../Types/Private/PageBlock.h"

//begin namespace block
namespace COMMON
{
class PageBlockPhoto : public PRIVATE::PageBlock
{
public:
	PageBlockPhoto();
	PageBlockPhoto(unsigned long long photo_id, PRIVATE::RichText* caption);

	~PageBlockPhoto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetPhotoId() const
	{
		 return this->photo_id;
	}

	PRIVATE::RichText*  Getcaption() const
	{
		 return this->caption;
	}

private:
	unsigned long long photo_id;
	 PRIVATE::RichText* caption;
};
} //end namespace block
