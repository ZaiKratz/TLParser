#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class PageBlockBlockquote : public TLBaseObject
{
public:
	PageBlockBlockquote();
	PageBlockBlockquote(TLBaseObject* text, TLBaseObject* caption);

	~PageBlockBlockquote();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Gettext() const
	{
		 return this->text;
	}

	TLBaseObject*  Getcaption() const
	{
		 return this->caption;
	}

private:
	TLBaseObject* text;
	 TLBaseObject* caption;
};
} //end namespace block
