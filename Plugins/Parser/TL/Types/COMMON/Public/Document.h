#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/PhotoSize.h"
#include "../../../Types/Private/DocumentAttribute.h"

//begin namespace block
namespace COMMON
{
class Document : public TLBaseObject
{
public:
	Document();
	Document(unsigned long long id, unsigned long long access_hash, FDateTime date, FString mime_type, int32 size, COMMON::PhotoSize* thumb, int32 dc_id, int32 version, TArray<PRIVATE::DocumentAttribute*> attributes);

	~Document();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long id;
	 unsigned long long access_hash;
	 FDateTime date;
	 FString mime_type;
	 int32 size;
	 COMMON::PhotoSize* thumb;
	 int32 dc_id;
	 int32 version;
	 TArray<PRIVATE::DocumentAttribute*> attributes;
};
} //end namespace block
