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
private:
	bool can_edit;
	 int32 user_id;
	 int32 inviter_id;
	 int32 promoted_by;
	 FDateTime date;
	 COMMON::ChannelAdminRights* admin_rights;
};
} //end namespace block
