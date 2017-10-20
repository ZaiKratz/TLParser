#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class PageBlockList : public TLBaseObject
{
public:
	PageBlockList();
	PageBlockList(bool ordered, TArray<TLBaseObject*> items);

	~PageBlockList();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getordered() const
	{
		 return this->ordered;
	}

	TArray<TLBaseObject*>  Getitems() const
	{
		 return this->items;
	}

private:
	bool ordered;
	 TArray<TLBaseObject*> items;
};
} //end namespace block
