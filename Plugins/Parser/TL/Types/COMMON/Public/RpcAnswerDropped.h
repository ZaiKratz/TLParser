#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/RpcDropAnswer.h"

//begin namespace block
namespace COMMON
{
class RpcAnswerDropped : public TLBaseObject
{
public:
	RpcAnswerDropped();
	RpcAnswerDropped(unsigned long long msg_id, int32 seq_no, int32 bytes);

	~RpcAnswerDropped();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long msg_id;
	 int32 seq_no;
	 int32 bytes;
};
} //end namespace block
