#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputMedia.h"

#include "../../../Types/Private/InputMedia.h"

//begin namespace block
namespace COMMON
{
class InputMediaPhotoExternal : public PRIVATE::InputMedia
{
public:
	InputMediaPhotoExternal();
	InputMediaPhotoExternal(FString url, FString caption, int32 ttl_seconds);

	~InputMediaPhotoExternal();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString url;
	 FString caption;
	 int32 ttl_seconds;
};
} //end namespace block
