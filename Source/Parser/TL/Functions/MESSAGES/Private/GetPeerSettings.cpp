#include "../Public/GetPeerSettings.h"


//begin namespace block
namespace MESSAGES
{

GetPeerSettings::GetPeerSettings()
{
	this->_ConstructorID = 913498268;
	this->_ContentRelated = true;
}

GetPeerSettings::GetPeerSettings(TLBaseObject*  peer)
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
	if(this->peer)
	{
		delete this->peer;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
