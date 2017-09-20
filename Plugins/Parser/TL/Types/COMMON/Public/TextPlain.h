#pragma once
#include "Engine.h"
#include "../../../Types/Private/RichText.h"

#include "../../../Types/Private/RichText.h"

//begin namespace block
namespace COMMON
{
class TextPlain : public PRIVATE::RichText
{
public:
	TextPlain();
	TextPlain(FString text);

	~TextPlain();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString text;
};
} //end namespace block
