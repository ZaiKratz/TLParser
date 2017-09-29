#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/PhoneCallProtocol.h"
#include "../../../Types/Common/Public/PhoneCall.h"

//begin namespace block
namespace COMMON
{
class PhoneCallAccepted : public TLBaseObject
{
public:
	PhoneCallAccepted();
	PhoneCallAccepted(unsigned long long id, unsigned long long access_hash, FDateTime date, int32 admin_id, int32 participant_id, TArray<uint8> g_b, COMMON::PhoneCallProtocol* protocol);

	~PhoneCallAccepted();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long Getid() const
	{
		 return this->id;
	}

	unsigned long long GetAccessHash() const
	{
		 return this->access_hash;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

	int32 GetAdminId() const
	{
		 return this->admin_id;
	}

	int32 GetParticipantId() const
	{
		 return this->participant_id;
	}

	TArray<uint8>  GetGB() const
	{
		 return this->g_b;
	}

	COMMON::PhoneCallProtocol*  Getprotocol() const
	{
		 return this->protocol;
	}

private:
	unsigned long long id;
	 unsigned long long access_hash;
	 FDateTime date;
	 int32 admin_id;
	 int32 participant_id;
	 TArray<uint8> g_b;
	 COMMON::PhoneCallProtocol* protocol;
};
} //end namespace block
