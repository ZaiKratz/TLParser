#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessagesFilter.h"

#include "../../../Types/Private/MessagesFilter.h"

//begin namespace block
namespace COMMON
{
class InputMessagesFilterMusic : public PRIVATE::MessagesFilter
{
public:
	InputMessagesFilterMusic();
	~InputMessagesFilterMusic();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
