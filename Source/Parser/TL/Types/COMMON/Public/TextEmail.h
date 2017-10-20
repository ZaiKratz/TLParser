#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class TextEmail : public TLBaseObject
{
public:
	TextEmail();
	TextEmail(TLBaseObject* text, FString email);

	~TextEmail();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Gettext() const
	{
		 return this->text;
	}

	FString Getemail() const
	{
		 return this->email;
	}

private:
	TLBaseObject* text;
	 FString email;
};
} //end namespace block
