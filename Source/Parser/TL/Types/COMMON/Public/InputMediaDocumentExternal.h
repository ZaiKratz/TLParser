#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputMedia.h"

#include "../../../Types/Private/InputMedia.h"

//begin namespace block
namespace COMMON
{
class InputMediaDocumentExternal : public PRIVATE::InputMedia
{
public:
	InputMediaDocumentExternal();
	InputMediaDocumentExternal(FString url, FString caption, int32 ttl_seconds);

	~InputMediaDocumentExternal();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Geturl() const
	{
		 return this->url;
	}

	FString Getcaption() const
	{
		 return this->caption;
	}

	int32 GetTtlSeconds() const
	{
		 return this->ttl_seconds;
	}

private:
	FString url;
	 FString caption;
	 int32 ttl_seconds;
};
} //end namespace block
