#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputMedia.h"

#include "../../../Types/Private/InputMedia.h"

//begin namespace block
namespace COMMON
{
class InputMediaGifExternal : public PRIVATE::InputMedia
{
public:
	InputMediaGifExternal();
	InputMediaGifExternal(FString url, FString q);

	~InputMediaGifExternal();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString url;
	 FString q;
};
} //end namespace block
