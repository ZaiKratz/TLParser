#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/MsgDetailedInfo.h"

//begin namespace block
namespace COMMON
{
class MsgNewDetailedInfo : public TLBaseObject
{
public:
	MsgNewDetailedInfo();
	MsgNewDetailedInfo(unsigned long long answer_msg_id, int32 bytes, int32 status);

	~MsgNewDetailedInfo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long answer_msg_id;
	 int32 bytes;
	 int32 status;
};
} //end namespace block
