#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputPhoneCall.h"
#include "../../../Types/Common/Public/PhoneCallProtocol.h"
#include "../../../Types/Phone/Public/PhoneCall.h"

//begin namespace block
namespace PHONE
{
class ConfirmCall : public TLBaseObject
{
public:
	ConfirmCall();
	ConfirmCall(COMMON::InputPhoneCall* peer, TArray<uint8> g_a, unsigned long long key_fingerprint, COMMON::PhoneCallProtocol* protocol);

	~ConfirmCall();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputPhoneCall*  Getpeer() const
	{
		 return this->peer;
	}

	TArray<uint8>  GetGA() const
	{
		 return this->g_a;
	}

	unsigned long long GetKeyFingerprint() const
	{
		 return this->key_fingerprint;
	}

	COMMON::PhoneCallProtocol*  Getprotocol() const
	{
		 return this->protocol;
	}

	PHONE::PhoneCall* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputPhoneCall* peer;
	 TArray<uint8> g_a;
	 unsigned long long key_fingerprint;
	 COMMON::PhoneCallProtocol* protocol;
	PHONE::PhoneCall* result;
};
} //end namespace block
