#pragma once
#include "Engine.h"
#include "../../../Types/Private/PageBlock.h"

#include "../../../Types/Private/RichText.h"
#include "../../../Types/Private/PageBlock.h"

//begin namespace block
namespace COMMON
{
class PageBlockPreformatted : public PRIVATE::PageBlock
{
public:
	PageBlockPreformatted();
	PageBlockPreformatted(PRIVATE::RichText* text, FString language);

	~PageBlockPreformatted();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	PRIVATE::RichText*  Gettext() const
	{
		 return this->text;
	}

	FString Getlanguage() const
	{
		 return this->language;
	}

private:
	PRIVATE::RichText* text;
	 FString language;
};
} //end namespace block
