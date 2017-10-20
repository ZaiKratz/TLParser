#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class TextPlain : public TLBaseObject
{
public:
	TextPlain();
	TextPlain(FString text);

	~TextPlain();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Gettext() const
	{
		 return this->text;
	}

private:
	FString text;
};
} //end namespace block
