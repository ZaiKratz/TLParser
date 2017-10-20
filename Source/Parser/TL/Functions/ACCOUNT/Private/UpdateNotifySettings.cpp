#include "../Public/UpdateNotifySettings.h"


//begin namespace block
namespace ACCOUNT
{

UpdateNotifySettings::UpdateNotifySettings()
{
	this->_ConstructorID = -2067899501;
	this->_ContentRelated = true;
}

UpdateNotifySettings::UpdateNotifySettings(COMMON::InputNotifyPeer*  peer, COMMON::InputPeerNotifySettings*  settings)
{
	this->_ConstructorID = -2067899501;
	this->_ContentRelated = true;
	this->peer = peer;
	this->settings = settings;
}
void UpdateNotifySettings::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	this->settings->OnSend(Writer);
}


void UpdateNotifySettings::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
UpdateNotifySettings::~UpdateNotifySettings()
{
	if(this->peer)
	{
		delete this->peer;
	}
	if(this->settings)
	{
		delete this->settings;
	}
}
}//end namespace block
