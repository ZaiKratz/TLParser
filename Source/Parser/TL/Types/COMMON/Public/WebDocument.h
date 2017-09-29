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

	FString Geturl() const
	{
		 return this->url;
	}

	unsigned long long GetAccessHash() const
	{
		 return this->access_hash;
	}

	int32 Getsize() const
	{
		 return this->size;
	}

	FString GetMimeType() const
	{
		 return this->mime_type;
	}

	TArray<PRIVATE::DocumentAttribute*>  Getattributes() const
	{
		 return this->attributes;
	}

	int32 GetDcId() const
	{
		 return this->dc_id;
	}

private:
	FString url;
	 unsigned long long access_hash;
	 int32 size;
	 FString mime_type;
	 TArray<PRIVATE::DocumentAttribute*> attributes;
	 int32 dc_id;
};
} //end namespace block
