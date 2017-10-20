#include "../Public/TopPeer.h"


//begin namespace block
namespace COMMON
{

TopPeer::TopPeer()
{
	this->_ConstructorID = -305282981;
}

TopPeer::TopPeer(TLBaseObject*  peer, double rating)
{
	this->_ConstructorID = -305282981;
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
	peer = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	rating = Reader.ReadDouble();
	this->_Responded = true;
}
TopPeer::~TopPeer()
{
	if(this->peer)
	{
		delete this->peer;
	}
}
}//end namespace block
