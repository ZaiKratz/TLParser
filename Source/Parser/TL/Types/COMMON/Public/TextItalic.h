#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class TextItalic : public TLBaseObject
{
public:
	TextItalic();
	TextItalic(TLBaseObject* text);

	~TextItalic();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Gettext() const
	{
		 return this->text;
	}

private:
	TLBaseObject* text;
};
} //end namespace block
