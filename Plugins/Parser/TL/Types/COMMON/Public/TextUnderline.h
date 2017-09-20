#pragma once
#include "Engine.h"
#include "../../../Types/Private/RichText.h"

#include "../../../Types/Private/RichText.h"
#include "../../../Types/Private/RichText.h"

//begin namespace block
namespace COMMON
{
class TextUnderline : public PRIVATE::RichText
{
public:
	TextUnderline();
	TextUnderline(PRIVATE::RichText* text);

	~TextUnderline();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::RichText* text;
};
} //end namespace block
