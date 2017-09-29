#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ChannelAdminRights.h"
#include "../../../Types/Common/Public/ChannelParticipant.h"

//begin namespace block
namespace COMMON
{
class ChannelParticipantAdmin : public TLBaseObject
{
public:
	ChannelParticipantAdmin();
	ChannelParticipantAdmin(bool can_edit, int32 user_id, int32 inviter_id, int32 promoted_by, FDateTime date, COMMON::ChannelAdminRights* admin_rights);

	~ChannelParticipantAdmin();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetCanEdit() const
	{
		 return this->can_edit;
	}

	int32 GetUserId() const
	{
		 return this->user_id;
	}

	int32 GetInviterId() const
	{
		 return this->inviter_id;
	}

	int32 GetPromotedBy() const
	{
		 return this->promoted_by;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

	COMMON::ChannelAdminRights*  GetAdminRights() const
	{
		 return this->admin_rights;
	}

private:
	bool can_edit;
	 int32 user_id;
	 int32 inviter_id;
	 int32 promoted_by;
	 FDateTime date;
	 COMMON::ChannelAdminRights* admin_rights;
};
} //end namespace block
