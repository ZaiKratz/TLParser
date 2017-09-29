#include "../Public/ExportInvite.h"


//begin namespace block
namespace CHANNELS
{

ExportInvite::ExportInvite()
{
	this->_ConstructorID = -950663035;
	this->_ContentRelated = true;
}

ExportInvite::ExportInvite(COMMON::InputChannel*  channel)
{
	this->_ConstructorID = -950663035;
	this->_ContentRelated = true;
	this->channel = channel;
}
void ExportInvite::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
}


void ExportInvite::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<PRIVATE::ExportedChatInvite*>(Reader.TGReadObject());
	this->_Responded = true;
}
ExportInvite::~ExportInvite()
{

}
}//end namespace block
