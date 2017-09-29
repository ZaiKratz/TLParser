#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace MESSAGES
{
class StartBot : public TLBaseObject
{
public:
	StartBot();
	StartBot(COMMON::InputUser* bot, PRIVATE::InputPeer* peer, unsigned long long random_id, FString start_param);

	~StartBot();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputUser*  Getbot() const
	{
		 return this->bot;
	}

	PRIVATE::InputPeer*  Getpeer() const
	{
		 return this->peer;
	}

	unsigned long long GetRandomId() const
	{
		 return this->random_id;
	}

	FString GetStartParam() const
	{
		 return this->start_param;
	}

	COMMON::Updates* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputUser* bot;
	 PRIVATE::InputPeer* peer;
	 unsigned long long random_id;
	 FString start_param;
	COMMON::Updates* result;
};
} //end namespace block
