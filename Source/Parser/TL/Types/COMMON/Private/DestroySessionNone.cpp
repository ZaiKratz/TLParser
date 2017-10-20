#include "../Public/DestroySessionNone.h"


//begin namespace block
namespace COMMON
{

DestroySessionNone::DestroySessionNone()
{
	this->_ConstructorID = 1658015945;
}

DestroySessionNone::DestroySessionNone(unsigned long long session_id)
{
	this->_ConstructorID = 1658015945;
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
	this->_Responded = true;
}
DestroySessionNone::~DestroySessionNone()
{
}
}//end namespace block
