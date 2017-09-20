#pragma once
#include "Engine.h"
#include "../../../Types/Private/DocumentAttribute.h"

#include "../../../Types/Private/DocumentAttribute.h"

//begin namespace block
namespace COMMON
{
class DocumentAttributeImageSize : public PRIVATE::DocumentAttribute
{
public:
	DocumentAttributeImageSize();
	DocumentAttributeImageSize(int32 w, int32 h);

	~DocumentAttributeImageSize();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 w;
	 int32 h;
};
} //end namespace block
