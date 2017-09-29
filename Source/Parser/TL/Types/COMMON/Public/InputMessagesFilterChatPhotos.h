#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessagesFilter.h"

#include "../../../Types/Private/MessagesFilter.h"

//begin namespace block
namespace COMMON
{
class InputMessagesFilterChatPhotos : public PRIVATE::MessagesFilter
{
public:
	InputMessagesFilterChatPhotos();
	~InputMessagesFilterChatPhotos();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
