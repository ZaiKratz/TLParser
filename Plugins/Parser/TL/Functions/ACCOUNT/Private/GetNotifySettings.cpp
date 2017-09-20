#include "../Public/GetNotifySettings.h"


//begin namespace block
namespace ACCOUNT
{

GetNotifySettings::GetNotifySettings()
{
	this->_ConstructorID = 833467154;
	this->_ContentRelated = true;
}

GetNotifySettings::GetNotifySettings(COMMON::InputNotifyPeer* peer)
{
	this->_ConstructorID = 833467154;
	this->_ContentRelated = true;
	this->peer = peer;
}
void GetNotifySettings::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
}


void GetNotifySettings::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::PeerNotifySettings*>(Reader.TGReadObject());
}
GetNotifySettings::~GetNotifySettings()
{

}
}//end namespace block