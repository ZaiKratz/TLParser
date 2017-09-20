#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/EncryptedChat.h"

//begin namespace block
namespace COMMON
{
class EncryptedChatWaiting : public TLBaseObject
{
public:
	EncryptedChatWaiting();
	EncryptedChatWaiting(int32 id, unsigned long long access_hash, FDateTime date, int32 admin_id, int32 participant_id);

	~EncryptedChatWaiting();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 id;
	 unsigned long long access_hash;
	 FDateTime date;
	 int32 admin_id;
	 int32 participant_id;
};
} //end namespace block
