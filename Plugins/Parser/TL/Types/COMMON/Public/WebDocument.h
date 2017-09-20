#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/DocumentAttribute.h"

//begin namespace block
namespace COMMON
{
class WebDocument : public TLBaseObject
{
public:
	WebDocument();
	WebDocument(FString url, unsigned long long access_hash, int32 size, FString mime_type, TArray<PRIVATE::DocumentAttribute*> attributes, int32 dc_id);

	~WebDocument();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString url;
	 unsigned long long access_hash;
	 int32 size;
	 FString mime_type;
	 TArray<PRIVATE::DocumentAttribute*> attributes;
	 int32 dc_id;
};
} //end namespace block
