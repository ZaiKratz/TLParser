#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputWebDocument : public TLBaseObject
{
public:
	InputWebDocument();
	InputWebDocument(FString url, int32 size, FString mime_type, TArray<TLBaseObject*> attributes);

	~InputWebDocument();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Geturl() const
	{
		 return this->url;
	}

	int32 Getsize() const
	{
		 return this->size;
	}

	FString GetMimeType() const
	{
		 return this->mime_type;
	}

	TArray<TLBaseObject*>  Getattributes() const
	{
		 return this->attributes;
	}

private:
	FString url;
	 int32 size;
	 FString mime_type;
	 TArray<TLBaseObject*> attributes;
};
} //end namespace block
