#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace MESSAGES
{
class SendScreenshotNotification : public TLBaseObject
{
public:
	SendScreenshotNotification();
	SendScreenshotNotification(PRIVATE::InputPeer* peer, int32 reply_to_msg_id, unsigned long long random_id);

	~SendScreenshotNotification();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::InputPeer* peer;
	 int32 reply_to_msg_id;
	 unsigned long long random_id;
	COMMON::Updates* result;
};
} //end namespace block
