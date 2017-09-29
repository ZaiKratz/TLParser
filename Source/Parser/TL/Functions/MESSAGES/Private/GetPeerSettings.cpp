#include "../Public/GetPeerSettings.h"


//begin namespace block
namespace MESSAGES
{

GetPeerSettings::GetPeerSettings()
{
	this->_ConstructorID = 913498268;
	this->_ContentRelated = true;
}

GetPeerSettings::GetPeerSettings(PRIVATE::InputPeer*  peer)
{
	this->_ConstructorID = 913498268;
	this->_ContentRelated = true;
	this->peer = peer;
}
void GetPeerSettings::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
}


void GetPeerSettings::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::PeerSettings*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetPeerSettings::~GetPeerSettings()
{

}
}//end namespace block