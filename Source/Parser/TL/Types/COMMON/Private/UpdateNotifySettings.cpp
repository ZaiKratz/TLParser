#include "../Public/UpdateNotifySettings.h"


//begin namespace block
namespace COMMON
{

UpdateNotifySettings::UpdateNotifySettings()
{
	this->_ConstructorID = -1094555409;
}

UpdateNotifySettings::UpdateNotifySettings(COMMON::NotifyPeer*  peer, COMMON::PeerNotifySettings*  notify_settings)
{
	this->_ConstructorID = -1094555409;
	this->peer = peer;
	this->notify_settings = notify_settings;
}
void UpdateNotifySettings::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	this->notify_settings->OnSend(Writer);
}


void UpdateNotifySettings::OnResponce(BinaryReader& Reader)
{
	peer = reinterpret_cast<COMMON::NotifyPeer* >(Reader.TGReadObject());
	notify_settings = reinterpret_cast<COMMON::PeerNotifySettings* >(Reader.TGReadObject());
	this->_Responded = true;
}
UpdateNotifySettings::~UpdateNotifySettings()
{

}
}//end namespace block
