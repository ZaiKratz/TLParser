#pragma once
#include "Engine.h"
#include "../../../Types/Private/DocumentAttribute.h"

#include "../../../Types/Private/DocumentAttribute.h"

//begin namespace block
namespace COMMON
{
class DocumentAttributeHasStickers : public PRIVATE::DocumentAttribute
{
public:
	DocumentAttributeHasStickers();
	~DocumentAttributeHasStickers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
