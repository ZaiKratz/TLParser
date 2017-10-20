#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class PageBlockAuthorDate : public TLBaseObject
{
public:
	PageBlockAuthorDate();
	PageBlockAuthorDate(TLBaseObject* author, FDateTime published_date);

	~PageBlockAuthorDate();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getauthor() const
	{
		 return this->author;
	}

	FDateTime GetPublishedDate() const
	{
		 return this->published_date;
	}

private:
	TLBaseObject* author;
	 FDateTime published_date;
};
} //end namespace block
