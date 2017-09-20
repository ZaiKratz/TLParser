#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputMedia.h"

#include "../../../Types/Common/Public/InputPhoto.h"
#include "../../../Types/Private/InputMedia.h"

//begin namespace block
namespace COMMON
{
class InputMediaPhoto : public PRIVATE::InputMedia
{
public:
	InputMediaPhoto();
	InputMediaPhoto(COMMON::InputPhoto* id, FString caption, int32 ttl_seconds);

	~InputMediaPhoto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputPhoto* id;
	 FString caption;
	 int32 ttl_seconds;
};
} //end namespace block
