#pragma once
#include "Engine.h"
#include "../../../Types/Private/RichText.h"

#include "../../../Types/Private/RichText.h"
#include "../../../Types/Private/RichText.h"

//begin namespace block
namespace COMMON
{
class TextConcat : public PRIVATE::RichText
{
public:
	TextConcat();
	TextConcat(TArray<PRIVATE::RichText*> texts);

	~TextConcat();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<PRIVATE::RichText*> texts;
};
} //end namespace block
