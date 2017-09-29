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

	TArray<unsigned long long>  GetMsgIds() const
	{
		 return this->msg_ids;
	}

	TLBaseObject*  Getquery() const
	{
		 return this->query;
	}

	TLBaseObject* GetResult() const
	{
		 return this->result;
	}

private:
	TArray<unsigned long long> msg_ids;
	 TLBaseObject* query;
	TLBaseObject* result;
};
} //end namespace block
