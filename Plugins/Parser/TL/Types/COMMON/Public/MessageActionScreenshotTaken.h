#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageAction.h"

#include "../../../Types/Private/MessageAction.h"

//begin namespace block
namespace COMMON
{
class MessageActionScreenshotTaken : public PRIVATE::MessageAction
{
public:
	MessageActionScreenshotTaken();
	~MessageActionScreenshotTaken();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block