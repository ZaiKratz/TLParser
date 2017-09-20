#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/DocumentAttribute.h"

//begin namespace block
namespace COMMON
{
class InputWebDocument : public TLBaseObject
{
public:
	InputWebDocument();
	InputWebDocument(FString url, int32 size, FString mime_type, TArray<PRIVATE::DocumentAttribute*> attributes);

	~InputWebDocument();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString url;
	 int32 size;
	 FString mime_type;
	 TArray<PRIVATE::DocumentAttribute*> attributes;
};
} //end namespace block
