#pragma once
#include "Engine.h"
#include "../../../Types/Private/SendMessageAction.h"

#include "../../../Types/Private/SendMessageAction.h"

//begin namespace block
namespace COMMON
{
class SendMessageUploadDocumentAction : public PRIVATE::SendMessageAction
{
public:
	SendMessageUploadDocumentAction();
	SendMessageUploadDocumentAction(int32 progress);

	~SendMessageUploadDocumentAction();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getprogress() const
	{
		 return this->progress;
	}

private:
	int32 progress;
};
} //end namespace block
