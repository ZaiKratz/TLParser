#include "../Public/ChannelParticipantBanned.h"


//begin namespace block
namespace COMMON
{

ChannelParticipantBanned::ChannelParticipantBanned()
{
	this->_ConstructorID = 573315206;
}

ChannelParticipantBanned::ChannelParticipantBanned(bool left, int32 user_id, int32 kicked_by, FDateTime date, COMMON::ChannelBannedRights*  banned_rights)
{
	this->_ConstructorID = 573315206;
	this->left = left;
	this->user_id = user_id;
	this->kicked_by = kicked_by;
	this->date = date;
	this->banned_rights = banned_rights;
}
void ChannelParticipantBanned::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(left)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->user_id);
	Writer.WriteInt(this->kicked_by);
	Writer.TGWriteDate(this->date);
	this->banned_rights->OnSend(Writer);
}


void ChannelParticipantBanned::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		left = true;
	}
	user_id = Reader.ReadInt();
	kicked_by = Reader.ReadInt();
	date = Reader.TGReadDate();
	banned_rights = reinterpret_cast<COMMON::ChannelBannedRights* >(Reader.TGReadObject());
	this->_Responded = true;
}
ChannelParticipantBanned::~ChannelParticipantBanned()
{
	if(this->banned_rights)
	{
		delete this->banned_rights;
	}
}
}//end namespace block
