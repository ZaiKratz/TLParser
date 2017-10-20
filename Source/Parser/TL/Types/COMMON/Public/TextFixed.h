#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class TextFixed : public TLBaseObject
{
public:
	TextFixed();
	TextFixed(TLBaseObject* text);

	~TextFixed();
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
