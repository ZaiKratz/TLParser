#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/RpcDropAnswer.h"

//begin namespace block
namespace COMMON
{
class RpcAnswerDroppedRunning : public TLBaseObject
{
public:
	RpcAnswerDroppedRunning();
	~RpcAnswerDroppedRunning();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
