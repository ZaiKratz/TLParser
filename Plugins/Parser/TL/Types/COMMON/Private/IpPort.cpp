#include "../Public/IpPort.h"


//begin namespace block
namespace COMMON
{

IpPort::IpPort()
{
	this->_ConstructorID = 64;
}

IpPort::IpPort(int32 ipv4, int32 port)
{
	this->_ConstructorID = 64;
	this->ipv4 = ipv4;
	this->port = port;
}
void IpPort::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->ipv4);
	Writer.WriteInt(this->port);
}


void IpPort::OnResponce(BinaryReader& Reader)
{
	ipv4 = Reader.ReadInt();
	port = Reader.ReadInt();
}
IpPort::~IpPort()
{

}
}//end namespace block
