#pragma once
#include "Engine.h"
#include "../../../Types/Private/PageBlock.h"

#include "../../../Types/Private/RichText.h"
#include "../../../Types/Private/PageBlock.h"

//begin namespace block
namespace COMMON
{
class PageBlockSubheader : public PRIVATE::PageBlock
{
public:
	PageBlockSubheader();
	PageBlockSubheader(PRIVATE::RichText* text);

	~PageBlockSubheader();
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
