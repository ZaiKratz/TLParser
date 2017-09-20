#pragma once
#include "Engine.h"
#include "../../../Types/Private/RichText.h"

#include "../../../Types/Private/RichText.h"
#include "../../../Types/Private/RichText.h"

//begin namespace block
namespace COMMON
{
class TextBold : public PRIVATE::RichText
{
public:
	TextBold();
	TextBold(PRIVATE::RichText* text);

	~TextBold();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::RichText* text;
};
} //end namespace block
