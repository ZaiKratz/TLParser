#include "../Public/TopPeer.h"


//begin namespace block
namespace COMMON
{

TopPeer::TopPeer()
{
	this->_ConstructorID = 1539362285;
}

TopPeer::TopPeer(PRIVATE::Peer* peer, double rating)
{
	this->_ConstructorID = 1539362285;
	this->peer = peer;
	this->rating = rating;
}
void TopPeer::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	Writer.WriteDouble(this->rating);
}


void TopPeer::OnResponce(BinaryReader& Reader)
{
	peer = reinterpret_cast<PRIVATE::Peer*>(Reader.TGReadObject());
	rating = Reader.ReadDouble();
}
TopPeer::~TopPeer()
{

}
}//end namespace block
