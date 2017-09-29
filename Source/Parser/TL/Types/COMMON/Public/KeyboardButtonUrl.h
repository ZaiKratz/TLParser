#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/KeyboardButton.h"

//begin namespace block
namespace COMMON
{
class KeyboardButtonUrl : public TLBaseObject
{
public:
	KeyboardButtonUrl();
	KeyboardButtonUrl(FString text, FString url);

	~KeyboardButtonUrl();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Gettext() const
	{
		 return this->text;
	}

	FString Geturl() const
	{
		 return this->url;
	}

private:
	FString text;
	 FString url;
};
} //end namespace block
