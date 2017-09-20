#pragma once
#include "Engine.h"
#include "../../../Types/Private/RichText.h"

#include "../../../Types/Private/RichText.h"
#include "../../../Types/Private/RichText.h"

//begin namespace block
namespace COMMON
{
class TextEmail : public PRIVATE::RichText
{
public:
	TextEmail();
	TextEmail(PRIVATE::RichText* text, FString email);

	~TextEmail();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::RichText* text;
	 FString email;
};
} //end namespace block
