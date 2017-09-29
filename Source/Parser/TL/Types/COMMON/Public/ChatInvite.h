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

	bool Getchannel() const
	{
		 return this->channel;
	}

	bool Getbroadcast() const
	{
		 return this->broadcast;
	}

	bool GetPublic() const
	{
		 return this->Public;
	}

	bool Getmegagroup() const
	{
		 return this->megagroup;
	}

	FString Gettitle() const
	{
		 return this->title;
	}

	COMMON::ChatPhoto*  Getphoto() const
	{
		 return this->photo;
	}

	int32 GetParticipantsCount() const
	{
		 return this->participants_count;
	}

	TArray<COMMON::User*>  Getparticipants() const
	{
		 return this->participants;
	}

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
