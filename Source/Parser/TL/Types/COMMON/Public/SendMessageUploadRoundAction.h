#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class SendMessageUploadRoundAction : public TLBaseObject
{
public:
	SendMessageUploadRoundAction();
	SendMessageUploadRoundAction(int32 progress);

	~SendMessageUploadRoundAction();
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
