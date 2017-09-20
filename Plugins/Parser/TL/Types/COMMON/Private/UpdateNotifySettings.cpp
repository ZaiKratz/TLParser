#include "../Public/UpdateNotifySettings.h"


//begin namespace block
namespace COMMON
{

UpdateNotifySettings::UpdateNotifySettings()
{
	this->_ConstructorID = -278347074;
}

UpdateNotifySettings::UpdateNotifySettings(COMMON::NotifyPeer* peer, COMMON::PeerNotifySettings* notify_settings)
{
	this->_ConstructorID = -278347074;
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
	peer = reinterpret_cast<COMMON::NotifyPeer*>(Reader.TGReadObject());
	notify_settings = reinterpret_cast<COMMON::PeerNotifySettings*>(Reader.TGReadObject());
}
UpdateNotifySettings::~UpdateNotifySettings()
{

}
}//end namespace block
