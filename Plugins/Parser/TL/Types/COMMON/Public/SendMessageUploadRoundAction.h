#pragma once
#include "Engine.h"
#include "../../../Types/Private/SendMessageAction.h"

#include "../../../Types/Private/SendMessageAction.h"

//begin namespace block
namespace COMMON
{
class SendMessageUploadRoundAction : public PRIVATE::SendMessageAction
{
public:
	SendMessageUploadRoundAction();
	SendMessageUploadRoundAction(int32 progress);

	~SendMessageUploadRoundAction();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 progress;
};
} //end namespace block
