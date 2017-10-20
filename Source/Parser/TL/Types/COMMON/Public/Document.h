#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/PhotoSize.h"

//begin namespace block
namespace COMMON
{
class Document : public TLBaseObject
{
public:
	Document();
	Document(unsigned long long id, unsigned long long access_hash, FDateTime date, FString mime_type, int32 size, COMMON::PhotoSize* thumb, int32 dc_id, int32 version, TArray<TLBaseObject*> attributes);

	~Document();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long Getid() const
	{
		 return this->id;
	}

	unsigned long long GetAccessHash() const
	{
		 return this->access_hash;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

	FString GetMimeType() const
	{
		 return this->mime_type;
	}

	int32 Getsize() const
	{
		 return this->size;
	}

	COMMON::PhotoSize*  Getthumb() const
	{
		 return this->thumb;
	}

	int32 GetDcId() const
	{
		 return this->dc_id;
	}

	int32 Getversion() const
	{
		 return this->version;
	}

	TArray<TLBaseObject*>  Getattributes() const
	{
		 return this->attributes;
	}

private:
	unsigned long long id;
	 unsigned long long access_hash;
	 FDateTime date;
	 FString mime_type;
	 int32 size;
	 COMMON::PhotoSize* thumb;
	 int32 dc_id;
	 int32 version;
	 TArray<TLBaseObject*> attributes;
};
} //end namespace block
