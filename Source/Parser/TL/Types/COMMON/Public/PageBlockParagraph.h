#pragma once
#include "Engine.h"
#include "../../../Types/Private/PageBlock.h"

#include "../../../Types/Private/RichText.h"
#include "../../../Types/Private/PageBlock.h"

//begin namespace block
namespace COMMON
{
class PageBlockParagraph : public PRIVATE::PageBlock
{
public:
	PageBlockParagraph();
	PageBlockParagraph(PRIVATE::RichText* text);

	~PageBlockParagraph();
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
