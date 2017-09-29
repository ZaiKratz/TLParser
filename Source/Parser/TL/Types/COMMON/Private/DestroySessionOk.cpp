#include "../Public/DestroySessionOk.h"


//begin namespace block
namespace COMMON
{

DestroySessionOk::DestroySessionOk()
{
	this->_ConstructorID = -501201412;
}

DestroySessionOk::DestroySessionOk(unsigned long long session_id)
{
	this->_ConstructorID = -501201412;
	this->session_id = session_id;
}
void DestroySessionOk::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->session_id);
}


void DestroySessionOk::OnResponce(BinaryReader& Reader)
{
	session_id = Reader.ReadLong();
	this->_Responded = true;
}
DestroySessionOk::~DestroySessionOk()
{

}
}//end namespace block
