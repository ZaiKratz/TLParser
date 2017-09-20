#pragma once
#include "Engine.h"
#include "../../../Types/Private/SendMessageAction.h"

#include "../../../Types/Private/SendMessageAction.h"

//begin namespace block
namespace COMMON
{
class SendMessageUploadPhotoAction : public PRIVATE::SendMessageAction
{
public:
	SendMessageUploadPhotoAction();
	SendMessageUploadPhotoAction(int32 progress);

	~SendMessageUploadPhotoAction();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 progress;
};
} //end namespace block
