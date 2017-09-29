#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class Pong : public TLBaseObject
{
public:
	Pong();
	Pong(unsigned long long msg_id, unsigned long long ping_id);

	~Pong();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetMsgId() const
	{
		 return this->msg_id;
	}

	unsigned long long GetPingId() const
	{
		 return this->ping_id;
	}

private:
	unsigned long long msg_id;
	 unsigned long long ping_id;
};
} //end namespace block
