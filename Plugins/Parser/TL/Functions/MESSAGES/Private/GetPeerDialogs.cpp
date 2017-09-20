#include "../Public/GetPeerDialogs.h"


//begin namespace block
namespace MESSAGES
{

GetPeerDialogs::GetPeerDialogs()
{
	this->_ConstructorID = -1183410387;
	this->_ContentRelated = true;
}

GetPeerDialogs::GetPeerDialogs(TArray<PRIVATE::InputPeer*> peers)
{
	this->_ConstructorID = -1183410387;
	this->_ContentRelated = true;
	this->peers = peers;
}
void GetPeerDialogs::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->peers.Num());
	for(auto X : this->peers)
	{
	X->OnSend(Writer);
	}
}


void GetPeerDialogs::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::PeerDialogs*>(Reader.TGReadObject());
}
GetPeerDialogs::~GetPeerDialogs()
{

}
}//end namespace block
