#include "../Public/InputNotifyPeer.h"


//begin namespace block
namespace COMMON
{

InputNotifyPeer::InputNotifyPeer()
{
	this->_ConstructorID = -1195615476;
}

InputNotifyPeer::InputNotifyPeer(TLBaseObject*  peer)
{
	this->_ConstructorID = -1195615476;
	this->peer = peer;
}
void InputNotifyPeer::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
}


void InputNotifyPeer::OnResponce(BinaryReader& Reader)
{
	peer = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
InputNotifyPeer::~InputNotifyPeer()
{
	if(this->peer)
	{
		delete this->peer;
	}
}
}//end namespace block
