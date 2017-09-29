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

}
}//end namespace block
