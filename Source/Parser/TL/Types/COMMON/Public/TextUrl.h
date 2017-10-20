#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class TextUrl : public TLBaseObject
{
public:
	TextUrl();
	TextUrl(TLBaseObject* text, FString url, unsigned long long webpage_id);

	~TextUrl();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Gettext() const
	{
		 return this->text;
	}

	FString Geturl() const
	{
		 return this->url;
	}

	unsigned long long GetWebpageId() const
	{
		 return this->webpage_id;
	}

private:
	TLBaseObject* text;
	 FString url;
	 unsigned long long webpage_id;
};
} //end namespace block
