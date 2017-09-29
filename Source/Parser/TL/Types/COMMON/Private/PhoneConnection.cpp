#include "../Public/PhoneConnection.h"


//begin namespace block
namespace COMMON
{

PhoneConnection::PhoneConnection()
{
	this->_ConstructorID = -1655957568;
}

PhoneConnection::PhoneConnection(unsigned long long id, FString ip, FString ipv6, int32 port, TArray<uint8>  peer_tag)
{
	this->_ConstructorID = -1655957568;
	this->id = id;
	this->ip = ip;
	this->ipv6 = ipv6;
	this->port = port;
	this->peer_tag = peer_tag;
}
void PhoneConnection::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
	Writer.TGWriteString(this->ip);
	Writer.TGWriteString(this->ipv6);
	Writer.WriteInt(this->port);
	Writer.TGWriteBytes((unsigned char*)this->peer_tag.GetData(), this->peer_tag.Num());
}


void PhoneConnection::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
	ip = Reader.TGReadString();
	ipv6 = Reader.TGReadString();
	port = Reader.ReadInt();
	peer_tag = Reader.TGReadBytes();
	this->_Responded = true;
}
PhoneConnection::~PhoneConnection()
{

}
}//end namespace block
