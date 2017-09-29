#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class SetBotPrecheckoutResults : public TLBaseObject
{
public:
	SetBotPrecheckoutResults();
	SetBotPrecheckoutResults(bool success, unsigned long long query_id, FString error);

	~SetBotPrecheckoutResults();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getsuccess() const
	{
		 return this->success;
	}

	unsigned long long GetQueryId() const
	{
		 return this->query_id;
	}

	FString Geterror() const
	{
		 return this->error;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	bool success;
	 unsigned long long query_id;
	 FString error;
	bool result;
};
} //end namespace block
