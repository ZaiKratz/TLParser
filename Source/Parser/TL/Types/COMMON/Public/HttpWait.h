#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class HttpWait : public TLBaseObject
{
public:
	HttpWait();
	HttpWait(int32 max_delay, int32 wait_after, int32 max_wait);

	~HttpWait();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetMaxDelay() const
	{
		 return this->max_delay;
	}

	int32 GetWaitAfter() const
	{
		 return this->wait_after;
	}

	int32 GetMaxWait() const
	{
		 return this->max_wait;
	}

private:
	int32 max_delay;
	 int32 wait_after;
	 int32 max_wait;
};
} //end namespace block
