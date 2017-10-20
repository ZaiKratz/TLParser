#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class PageBlockPreformatted : public TLBaseObject
{
public:
	PageBlockPreformatted();
	PageBlockPreformatted(TLBaseObject* text, FString language);

	~PageBlockPreformatted();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Gettext() const
	{
		 return this->text;
	}

	FString Getlanguage() const
	{
		 return this->language;
	}

private:
	TLBaseObject* text;
	 FString language;
};
} //end namespace block
