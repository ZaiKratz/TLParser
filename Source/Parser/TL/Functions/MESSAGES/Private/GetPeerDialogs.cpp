#include "../Public/GetPeerDialogs.h"


//begin namespace block
namespace MESSAGES
{

GetPeerDialogs::GetPeerDialogs()
{
	this->_ConstructorID = 764901049;
	this->_ContentRelated = true;
}

GetPeerDialogs::GetPeerDialogs(TArray<TLBaseObject*>  peers)
{
	this->_ConstructorID = 764901049;
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
	this->_Responded = true;
}
GetPeerDialogs::~GetPeerDialogs()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
