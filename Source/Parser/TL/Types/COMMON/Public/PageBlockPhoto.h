#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class PageBlockPhoto : public TLBaseObject
{
public:
	PageBlockPhoto();
	PageBlockPhoto(unsigned long long photo_id, TLBaseObject* caption);

	~PageBlockPhoto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetPhotoId() const
	{
		 return this->photo_id;
	}

	TLBaseObject*  Getcaption() const
	{
		 return this->caption;
	}

private:
	unsigned long long photo_id;
	 TLBaseObject* caption;
};
} //end namespace block
