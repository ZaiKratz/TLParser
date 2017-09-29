#pragma once
#include "Engine.h"
#include "../../../Types/Private/RichText.h"

#include "../../../Types/Private/RichText.h"

//begin namespace block
namespace COMMON
{
class TextEmpty : public PRIVATE::RichText
{
public:
	TextEmpty();
	~TextEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
