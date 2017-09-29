#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/PhoneCallProtocol.h"
#include "../../../Types/Common/Public/PhoneConnection.h"

//begin namespace block
namespace COMMON
{
class PhoneCall : public TLBaseObject
{
public:
	PhoneCall();
	PhoneCall(unsigned long long id, unsigned long long access_hash, FDateTime date, int32 admin_id, int32 participant_id, TArray<uint8> g_a_or_b, unsigned long long key_fingerprint, COMMON::PhoneCallProtocol* protocol, COMMON::PhoneConnection* connection, TArray<COMMON::PhoneConnection*> alternative_connections, FDateTime start_date);

	~PhoneCall();
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

	TArray<uint8>  GetGAOrB() const
	{
		 return this->g_a_or_b;
	}

	unsigned long long GetKeyFingerprint() const
	{
		 return this->key_fingerprint;
	}

	COMMON::PhoneCallProtocol*  Getprotocol() const
	{
		 return this->protocol;
	}

	COMMON::PhoneConnection*  Getconnection() const
	{
		 return this->connection;
	}

	TArray<COMMON::PhoneConnection*>  GetAlternativeConnections() const
	{
		 return this->alternative_connections;
	}

	FDateTime GetStartDate() const
	{
		 return this->start_date;
	}

private:
	unsigned long long id;
	 unsigned long long access_hash;
	 FDateTime date;
	 int32 admin_id;
	 int32 participant_id;
	 TArray<uint8> g_a_or_b;
	 unsigned long long key_fingerprint;
	 COMMON::PhoneCallProtocol* protocol;
	 COMMON::PhoneConnection* connection;
	 TArray<COMMON::PhoneConnection*> alternative_connections;
	 FDateTime start_date;
};
} //end namespace block
