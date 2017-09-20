#pragma once
#include "Engine.h"
#include "../../../Types/Private/SendMessageAction.h"

#include "../../../Types/Private/SendMessageAction.h"

//begin namespace block
namespace COMMON
{
class SendMessageUploadAudioAction : public PRIVATE::SendMessageAction
{
public:
	SendMessageUploadAudioAction();
	SendMessageUploadAudioAction(int32 progress);

	~SendMessageUploadAudioAction();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 progress;
};
} //end namespace block
