#pragma once
#include "Engine.h"
#include "../../../Types/Private/PageBlock.h"

#include "../../../Types/Private/RichText.h"
#include "../../../Types/Private/PageBlock.h"

//begin namespace block
namespace COMMON
{
class PageBlockAuthorDate : public PRIVATE::PageBlock
{
public:
	PageBlockAuthorDate();
	PageBlockAuthorDate(PRIVATE::RichText* author, FDateTime published_date);

	~PageBlockAuthorDate();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	PRIVATE::RichText*  Getauthor() const
	{
		 return this->author;
	}

	FDateTime GetPublishedDate() const
	{
		 return this->published_date;
	}

private:
	PRIVATE::RichText* author;
	 FDateTime published_date;
};
} //end namespace block
