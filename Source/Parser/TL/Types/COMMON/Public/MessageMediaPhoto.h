#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageMedia.h"

#include "../../../Types/Common/Public/Photo.h"
#include "../../../Types/Private/MessageMedia.h"

//begin namespace block
namespace COMMON
{
class MessageMediaPhoto : public PRIVATE::MessageMedia
{
public:
	MessageMediaPhoto();
	MessageMediaPhoto(COMMON::Photo* photo, FString caption, int32 ttl_seconds);

	~MessageMediaPhoto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::Photo*  Getphoto() const
	{
		 return this->photo;
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
	COMMON::Photo* photo;
	 FString caption;
	 int32 ttl_seconds;
};
} //end namespace block
