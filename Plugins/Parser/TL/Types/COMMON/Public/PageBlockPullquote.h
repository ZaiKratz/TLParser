#pragma once
#include "Engine.h"
#include "../../../Types/Private/PageBlock.h"

#include "../../../Types/Private/RichText.h"
#include "../../../Types/Private/PageBlock.h"

//begin namespace block
namespace COMMON
{
class PageBlockPullquote : public PRIVATE::PageBlock
{
public:
	PageBlockPullquote();
	PageBlockPullquote(PRIVATE::RichText* text, PRIVATE::RichText* caption);

	~PageBlockPullquote();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::RichText* text;
	 PRIVATE::RichText* caption;
};
} //end namespace block
