#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class ReceivedNotifyMessage : public TLBaseObject
{
public:
	ReceivedNotifyMessage();
	ReceivedNotifyMessage(int32 id, int32 flags);

	~ReceivedNotifyMessage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 id;
	 int32 flags;
};
} //end namespace block
