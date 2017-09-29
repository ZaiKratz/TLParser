#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Pong.h"

//begin namespace block
namespace COMMON
{
class PingDelayDisconnect : public TLBaseObject
{
public:
	PingDelayDisconnect();
	PingDelayDisconnect(unsigned long long ping_id, int32 disconnect_delay);

	~PingDelayDisconnect();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetPingId() const
	{
		 return this->ping_id;
	}

	int32 GetDisconnectDelay() const
	{
		 return this->disconnect_delay;
	}

	COMMON::Pong* GetResult() const
	{
		 return this->result;
	}

private:
	unsigned long long ping_id;
	 int32 disconnect_delay;
	COMMON::Pong* result;
};
} //end namespace block
