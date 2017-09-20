#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ChatPhoto.h"
#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace COMMON
{
class ChatInvite : public TLBaseObject
{
public:
	ChatInvite();
	ChatInvite(bool channel, bool broadcast, bool Public, bool megagroup, FString title, COMMON::ChatPhoto* photo, int32 participants_count, TArray<COMMON::User*> participants);

	~ChatInvite();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool channel;
	 bool broadcast;
	 bool Public;
	 bool megagroup;
	 FString title;
	 COMMON::ChatPhoto* photo;
	 int32 participants_count;
	 TArray<COMMON::User*> participants;
};
} //end namespace block
