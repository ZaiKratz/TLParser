#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InvokeAfterMsgs : public TLBaseObject
{
public:
	InvokeAfterMsgs();
	InvokeAfterMsgs(TArray<unsigned long long> msg_ids, TLBaseObject* query);

	~InvokeAfterMsgs();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<unsigned long long> msg_ids;
	 TLBaseObject* query;
	TLBaseObject* result;
};
} //end namespace block
