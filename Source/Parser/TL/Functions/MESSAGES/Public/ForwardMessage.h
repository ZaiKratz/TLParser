#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace MESSAGES
{
class ForwardMessage : public TLBaseObject
{
public:
	ForwardMessage();
	ForwardMessage(PRIVATE::InputPeer* peer, int32 id, unsigned long long random_id);

	~ForwardMessage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	PRIVATE::InputPeer*  Getpeer() const
	{
		 return this->peer;
	}

	int32 Getid() const
	{
		 return this->id;
	}

	unsigned long long GetRandomId() const
	{
		 return this->random_id;
	}

	COMMON::Updates* GetResult() const
	{
		 return this->result;
	}

private:
	PRIVATE::InputPeer* peer;
	 int32 id;
	 unsigned long long random_id;
	COMMON::Updates* result;
};
} //end namespace block
