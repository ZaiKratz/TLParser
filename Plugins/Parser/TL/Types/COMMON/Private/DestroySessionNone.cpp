#include "../Public/DestroySessionNone.h"


//begin namespace block
namespace COMMON
{

DestroySessionNone::DestroySessionNone()
{
	this->_ConstructorID = -917449886;
}

DestroySessionNone::DestroySessionNone(unsigned long long session_id)
{
	this->_ConstructorID = -917449886;
	this->session_id = session_id;
}
void DestroySessionNone::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->session_id);
}


void DestroySessionNone::OnResponce(BinaryReader& Reader)
{
	session_id = Reader.ReadLong();
}
DestroySessionNone::~DestroySessionNone()
{

}
}//end namespace block
