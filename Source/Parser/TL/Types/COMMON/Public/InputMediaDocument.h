#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputMedia.h"

#include "../../../Types/Common/Public/InputDocument.h"
#include "../../../Types/Private/InputMedia.h"

//begin namespace block
namespace COMMON
{
class InputMediaDocument : public PRIVATE::InputMedia
{
public:
	InputMediaDocument();
	InputMediaDocument(COMMON::InputDocument* id, FString caption, int32 ttl_seconds);

	~InputMediaDocument();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputDocument*  Getid() const
	{
		 return this->id;
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
	COMMON::InputDocument* id;
	 FString caption;
	 int32 ttl_seconds;
};
} //end namespace block