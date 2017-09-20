#pragma once
#include "Engine.h"
#include "../../../Types/Private/RichText.h"

#include "../../../Types/Private/RichText.h"
#include "../../../Types/Private/RichText.h"

//begin namespace block
namespace COMMON
{
class TextStrike : public PRIVATE::RichText
{
public:
	TextStrike();
	TextStrike(PRIVATE::RichText* text);

	~TextStrike();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::RichText* text;
};
} //end namespace block
