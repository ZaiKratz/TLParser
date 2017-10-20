#include "../Public/PhoneCallProtocol.h"


//begin namespace block
namespace COMMON
{

PhoneCallProtocol::PhoneCallProtocol()
{
	this->_ConstructorID = -1564789301;
}

PhoneCallProtocol::PhoneCallProtocol(bool udp_p2p, bool udp_reflector, int32 min_layer, int32 max_layer)
{
	this->_ConstructorID = -1564789301;
	this->udp_p2p = udp_p2p;
	this->udp_reflector = udp_reflector;
	this->min_layer = min_layer;
	this->max_layer = max_layer;
}
void PhoneCallProtocol::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(udp_p2p)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(udp_reflector)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->min_layer);
	Writer.WriteInt(this->max_layer);
}


void PhoneCallProtocol::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		udp_p2p = true;
	}
	if((Flags & (1 << 1)) != 0) 
	{
		udp_reflector = true;
	}
	min_layer = Reader.ReadInt();
	max_layer = Reader.ReadInt();
	this->_Responded = true;
}
PhoneCallProtocol::~PhoneCallProtocol()
{
}
}//end namespace block
