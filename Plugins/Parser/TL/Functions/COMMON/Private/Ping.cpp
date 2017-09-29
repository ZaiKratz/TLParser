#include "../Public/Ping.h"


//begin namespace block
namespace COMMON
{

Ping::Ping()
{
	this->_ConstructorID = 2059302892;
	this->_ContentRelated = true;
}

Ping::Ping(unsigned long long ping_id)
{
	this->_ConstructorID = 2059302892;
	this->_ContentRelated = true;
	this->ping_id = ping_id;
}
void Ping::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->ping_id);
}


void Ping::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Pong*>(Reader.TGReadObject());
	this->_Responded = true;
}
Ping::~Ping()
{

}
}//end namespace block
