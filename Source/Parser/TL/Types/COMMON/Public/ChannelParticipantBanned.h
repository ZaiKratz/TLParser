#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ChannelBannedRights.h"
#include "../../../Types/Common/Public/ChannelParticipant.h"

//begin namespace block
namespace COMMON
{
class ChannelParticipantBanned : public TLBaseObject
{
public:
	ChannelParticipantBanned();
	ChannelParticipantBanned(bool left, int32 user_id, int32 kicked_by, FDateTime date, COMMON::ChannelBannedRights* banned_rights);

	~ChannelParticipantBanned();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getleft() const
	{
		 return this->left;
	}

	int32 GetUserId() const
	{
		 return this->user_id;
	}

	int32 GetKickedBy() const
	{
		 return this->kicked_by;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

	COMMON::ChannelBannedRights*  GetBannedRights() const
	{
		 return this->banned_rights;
	}

private:
	bool left;
	 int32 user_id;
	 int32 kicked_by;
	 FDateTime date;
	 COMMON::ChannelBannedRights* banned_rights;
};
} //end namespace block
