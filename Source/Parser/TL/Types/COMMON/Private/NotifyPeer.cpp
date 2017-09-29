#include "../Public/NotifyPeer.h"


//begin namespace block
namespace COMMON
{

NotifyPeer::NotifyPeer()
{
	this->_ConstructorID = -1613493288;
}

NotifyPeer::NotifyPeer(PRIVATE::Peer*  peer)
{
	this->_ConstructorID = -1613493288;
	this->peer = peer;
}
void NotifyPeer::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
}


void NotifyPeer::OnResponce(BinaryReader& Reader)
{
	peer = reinterpret_cast<PRIVATE::Peer* >(Reader.TGReadObject());
	this->_Responded = true;
}
NotifyPeer::~NotifyPeer()
{

}
}//end namespace block
