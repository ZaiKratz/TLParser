#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class FoundGif : public TLBaseObject
{
public:
	FoundGif();
	FoundGif(FString url, FString thumb_url, FString content_url, FString content_type, int32 w, int32 h);

	~FoundGif();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Geturl() const
	{
		 return this->url;
	}

	FString GetThumbUrl() const
	{
		 return this->thumb_url;
	}

	FString GetContentUrl() const
	{
		 return this->content_url;
	}

	FString GetContentType() const
	{
		 return this->content_type;
	}

	int32 Getw() const
	{
		 return this->w;
	}

	int32 Geth() const
	{
		 return this->h;
	}

private:
	FString url;
	 FString thumb_url;
	 FString content_url;
	 FString content_type;
	 int32 w;
	 int32 h;
};
} //end namespace block
