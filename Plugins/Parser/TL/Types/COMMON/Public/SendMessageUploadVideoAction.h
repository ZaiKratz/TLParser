#pragma once
#include "Engine.h"
#include "../../../Types/Private/SendMessageAction.h"

#include "../../../Types/Private/SendMessageAction.h"

//begin namespace block
namespace COMMON
{
class SendMessageUploadVideoAction : public PRIVATE::SendMessageAction
{
public:
	SendMessageUploadVideoAction();
	SendMessageUploadVideoAction(int32 progress);

	~SendMessageUploadVideoAction();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 progress;
};
} //end namespace block
