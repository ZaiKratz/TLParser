#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class PageBlockPullquote : public TLBaseObject
{
public:
	PageBlockPullquote();
	PageBlockPullquote(TLBaseObject* text, TLBaseObject* caption);

	~PageBlockPullquote();
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
