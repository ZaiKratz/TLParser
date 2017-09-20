#include "../Public/Pong.h"


//begin namespace block
namespace COMMON
{

Pong::Pong()
{
	this->_ConstructorID = -982288588;
}

Pong::Pong(unsigned long long msg_id, unsigned long long ping_id)
{
	this->_ConstructorID = -982288588;
	this->msg_id = msg_id;
	this->ping_id = ping_id;
}
void Pong::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->msg_id);
	Writer.WriteLong(this->ping_id);
}


void Pong::OnResponce(BinaryReader& Reader)
{
	msg_id = Reader.ReadLong();
	ping_id = Reader.ReadLong();
}
Pong::~Pong()
{

}
}//end namespace block
