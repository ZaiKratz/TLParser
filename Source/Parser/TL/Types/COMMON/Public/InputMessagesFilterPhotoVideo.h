#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessagesFilter.h"

#include "../../../Types/Private/MessagesFilter.h"

//begin namespace block
namespace COMMON
{
class InputMessagesFilterPhotoVideo : public PRIVATE::MessagesFilter
{
public:
	InputMessagesFilterPhotoVideo();
	~InputMessagesFilterPhotoVideo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
