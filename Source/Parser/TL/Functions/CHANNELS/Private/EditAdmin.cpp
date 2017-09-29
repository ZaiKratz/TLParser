#include "../Public/EditAdmin.h"


//begin namespace block
namespace CHANNELS
{

EditAdmin::EditAdmin()
{
	this->_ConstructorID = 548962836;
	this->_ContentRelated = true;
}

EditAdmin::EditAdmin(COMMON::InputChannel*  channel, COMMON::InputUser*  user_id, COMMON::ChannelAdminRights*  admin_rights)
{
	this->_ConstructorID = 548962836;
	this->_ContentRelated = true;
	this->channel = channel;
	this->user_id = user_id;
	this->admin_rights = admin_rights;
}
void EditAdmin::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
	this->user_id->OnSend(Writer);
	this->admin_rights->OnSend(Writer);
}


void EditAdmin::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
	this->_Responded = true;
}
EditAdmin::~EditAdmin()
{

}
}//end namespace block
