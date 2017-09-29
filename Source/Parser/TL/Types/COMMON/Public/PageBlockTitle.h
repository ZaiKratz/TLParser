#pragma once
#include "Engine.h"
#include "../../../Types/Private/PageBlock.h"

#include "../../../Types/Private/RichText.h"
#include "../../../Types/Private/PageBlock.h"

//begin namespace block
namespace COMMON
{
class PageBlockTitle : public PRIVATE::PageBlock
{
public:
	PageBlockTitle();
	PageBlockTitle(PRIVATE::RichText* text);

	~PageBlockTitle();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	PRIVATE::RichText*  Gettext() const
	{
		 return this->text;
	}

private:
	PRIVATE::RichText* text;
};
} //end namespace block
