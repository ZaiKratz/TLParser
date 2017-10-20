#include "../Public/ChannelParticipantAdmin.h"


//begin namespace block
namespace COMMON
{

ChannelParticipantAdmin::ChannelParticipantAdmin()
{
	this->_ConstructorID = -1473271656;
}

ChannelParticipantAdmin::ChannelParticipantAdmin(bool can_edit, int32 user_id, int32 inviter_id, int32 promoted_by, FDateTime date, COMMON::ChannelAdminRights*  admin_rights)
{
	this->_ConstructorID = -1473271656;
	this->can_edit = can_edit;
	this->user_id = user_id;
	this->inviter_id = inviter_id;
	this->promoted_by = promoted_by;
	this->date = date;
	this->admin_rights = admin_rights;
}
void ChannelParticipantAdmin::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(can_edit)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->user_id);
	Writer.WriteInt(this->inviter_id);
	Writer.WriteInt(this->promoted_by);
	Writer.TGWriteDate(this->date);
	this->admin_rights->OnSend(Writer);
}


void ChannelParticipantAdmin::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		can_edit = true;
	}
	user_id = Reader.ReadInt();
	inviter_id = Reader.ReadInt();
	promoted_by = Reader.ReadInt();
	date = Reader.TGReadDate();
	admin_rights = reinterpret_cast<COMMON::ChannelAdminRights* >(Reader.TGReadObject());
	this->_Responded = true;
}
ChannelParticipantAdmin::~ChannelParticipantAdmin()
{
	if(this->admin_rights)
	{
		delete this->admin_rights;
	}
}
}//end namespace block
