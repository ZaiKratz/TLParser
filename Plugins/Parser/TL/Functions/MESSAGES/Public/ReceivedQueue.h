#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class ReceivedQueue : public TLBaseObject
{
public:
	ReceivedQueue();
	ReceivedQueue(int32 max_qts);

	~ReceivedQueue();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetMaxQts() const
	{
		 return this->max_qts;
	}

	TArray<unsigned long long> GetResult() const
	{
		 return this->result;
	}

private:
	int32 max_qts;
	TArray<unsigned long long> result;
};
} //end namespace block
