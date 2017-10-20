#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class PageBlockSlideshow : public TLBaseObject
{
public:
	PageBlockSlideshow();
	PageBlockSlideshow(TArray<TLBaseObject*> items, TLBaseObject* caption);

	~PageBlockSlideshow();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<TLBaseObject*>  Getitems() const
	{
		 return this->items;
	}

	TLBaseObject*  Getcaption() const
	{
		 return this->caption;
	}

private:
	TArray<TLBaseObject*> items;
	 TLBaseObject* caption;
};
} //end namespace block
