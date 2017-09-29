#include "../Public/HttpWait.h"


//begin namespace block
namespace COMMON
{

HttpWait::HttpWait()
{
	this->_ConstructorID = -1835453025;
}

HttpWait::HttpWait(int32 max_delay, int32 wait_after, int32 max_wait)
{
	this->_ConstructorID = -1835453025;
	this->max_delay = max_delay;
	this->wait_after = wait_after;
	this->max_wait = max_wait;
}
void HttpWait::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->max_delay);
	Writer.WriteInt(this->wait_after);
	Writer.WriteInt(this->max_wait);
}


void HttpWait::OnResponce(BinaryReader& Reader)
{
	max_delay = Reader.ReadInt();
	wait_after = Reader.ReadInt();
	max_wait = Reader.ReadInt();
	this->_Responded = true;
}
HttpWait::~HttpWait()
{

}
}//end namespace block
