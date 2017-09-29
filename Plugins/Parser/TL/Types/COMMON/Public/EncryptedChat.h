#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class EncryptedChat : public TLBaseObject
{
public:
	EncryptedChat();
	EncryptedChat(int32 id, unsigned long long access_hash, FDateTime date, int32 admin_id, int32 participant_id, TArray<uint8> g_a_or_b, unsigned long long key_fingerprint);

	~EncryptedChat();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getid() const
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

private:
	int32 id;
	 unsigned long long access_hash;
	 FDateTime date;
	 int32 admin_id;
	 int32 participant_id;
	 TArray<uint8> g_a_or_b;
	 unsigned long long key_fingerprint;
};
} //end namespace block
