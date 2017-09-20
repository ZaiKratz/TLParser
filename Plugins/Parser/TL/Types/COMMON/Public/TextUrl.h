#pragma once
#include "Engine.h"
#include "../../../Types/Private/RichText.h"

#include "../../../Types/Private/RichText.h"
#include "../../../Types/Private/RichText.h"

//begin namespace block
namespace COMMON
{
class TextUrl : public PRIVATE::RichText
{
public:
	TextUrl();
	TextUrl(PRIVATE::RichText* text, FString url, unsigned long long webpage_id);

	~TextUrl();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::RichText* text;
	 FString url;
	 unsigned long long webpage_id;
};
} //end namespace block
