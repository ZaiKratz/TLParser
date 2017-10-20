#include "../Public/EditBanned.h"


//begin namespace block
namespace CHANNELS
{

EditBanned::EditBanned()
{
	this->_ConstructorID = -1076292147;
	this->_ContentRelated = true;
}

EditBanned::EditBanned(COMMON::InputChannel*  channel, COMMON::InputUser*  user_id, COMMON::ChannelBannedRights*  banned_rights)
{
	this->_ConstructorID = -1076292147;
	this->_ContentRelated = true;
	this->channel = channel;
	this->user_id = user_id;
	this->banned_rights = banned_rights;
}
void EditBanned::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
	this->user_id->OnSend(Writer);
	this->banned_rights->OnSend(Writer);
}


void EditBanned::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
	this->_Responded = true;
}
EditBanned::~EditBanned()
{
	if(this->channel)
	{
		delete this->channel;
	}
	if(this->user_id)
	{
		delete this->user_id;
	}
	if(this->banned_rights)
	{
		delete this->banned_rights;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
