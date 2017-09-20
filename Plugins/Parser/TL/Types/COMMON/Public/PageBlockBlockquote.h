#pragma once
#include "Engine.h"
#include "../../../Types/Private/PageBlock.h"

#include "../../../Types/Private/RichText.h"
#include "../../../Types/Private/PageBlock.h"

//begin namespace block
namespace COMMON
{
class PageBlockBlockquote : public PRIVATE::PageBlock
{
public:
	PageBlockBlockquote();
	PageBlockBlockquote(PRIVATE::RichText* text, PRIVATE::RichText* caption);

	~PageBlockBlockquote();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::RichText* text;
	 PRIVATE::RichText* caption;
};
} //end namespace block
