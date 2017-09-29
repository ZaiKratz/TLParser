#include "../Public/PingDelayDisconnect.h"


//begin namespace block
namespace COMMON
{

PingDelayDisconnect::PingDelayDisconnect()
{
	this->_ConstructorID = -213746804;
	this->_ContentRelated = true;
}

PingDelayDisconnect::PingDelayDisconnect(unsigned long long ping_id, int32 disconnect_delay)
{
	this->_ConstructorID = -213746804;
	this->_ContentRelated = true;
	this->ping_id = ping_id;
	this->disconnect_delay = disconnect_delay;
}
void PingDelayDisconnect::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->ping_id);
	Writer.WriteInt(this->disconnect_delay);
}


void PingDelayDisconnect::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Pong*>(Reader.TGReadObject());
	this->_Responded = true;
}
PingDelayDisconnect::~PingDelayDisconnect()
{

}
}//end namespace block
