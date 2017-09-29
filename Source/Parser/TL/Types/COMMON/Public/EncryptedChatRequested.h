#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/EncryptedChat.h"

//begin namespace block
namespace COMMON
{
class EncryptedChatRequested : public TLBaseObject
{
public:
	EncryptedChatRequested();
	EncryptedChatRequested(int32 id, unsigned long long access_hash, FDateTime date, int32 admin_id, int32 participant_id, TArray<uint8> g_a);

	~EncryptedChatRequested();
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

	TArray<uint8>  GetGA() const
	{
		 return this->g_a;
	}

private:
	int32 id;
	 unsigned long long access_hash;
	 FDateTime date;
	 int32 admin_id;
	 int32 participant_id;
	 TArray<uint8> g_a;
};
} //end namespace block
