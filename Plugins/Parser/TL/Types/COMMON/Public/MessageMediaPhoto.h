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
private:
	COMMON::Photo* photo;
	 FString caption;
	 int32 ttl_seconds;
};
} //end namespace block
