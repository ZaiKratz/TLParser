#pragma once
#include "Engine.h"
#include "../../../Types/Private/RichText.h"

#include "../../../Types/Private/RichText.h"
#include "../../../Types/Private/RichText.h"

//begin namespace block
namespace COMMON
{
class TextUrl : public PRIVATE::RichText
{
public:
	TextUrl();
	TextUrl(PRIVATE::RichText* text, FString url, unsigned long long webpage_id);

	~TextUrl();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	PRIVATE::RichText*  Gettext() const
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
	PRIVATE::RichText* text;
	 FString url;
	 unsigned long long webpage_id;
};
} //end namespace block
