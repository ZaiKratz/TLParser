#pragma once
#include "Engine.h"
#include "../../../Types/Private/PageBlock.h"

#include "../../../Types/Private/RichText.h"
#include "../../../Types/Private/PageBlock.h"

//begin namespace block
namespace COMMON
{
class PageBlockList : public PRIVATE::PageBlock
{
public:
	PageBlockList();
	PageBlockList(bool ordered, TArray<PRIVATE::RichText*> items);

	~PageBlockList();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getordered() const
	{
		 return this->ordered;
	}

	TArray<PRIVATE::RichText*>  Getitems() const
	{
		 return this->items;
	}

private:
	bool ordered;
	 TArray<PRIVATE::RichText*> items;
};
} //end namespace block
