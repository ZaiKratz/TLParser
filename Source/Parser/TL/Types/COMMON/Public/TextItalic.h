#pragma once
#include "Engine.h"
#include "../../../Types/Private/RichText.h"

#include "../../../Types/Private/RichText.h"
#include "../../../Types/Private/RichText.h"

//begin namespace block
namespace COMMON
{
class TextItalic : public PRIVATE::RichText
{
public:
	TextItalic();
	TextItalic(PRIVATE::RichText* text);

	~TextItalic();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	PRIVATE::RichText*  Gettext() const
	{
		 return this->text;
	}

private:
	PRIVATE::RichText* text;
};
} //end namespace block
