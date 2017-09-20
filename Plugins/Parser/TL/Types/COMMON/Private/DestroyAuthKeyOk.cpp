#include "../Public/DestroyAuthKeyOk.h"


//begin namespace block
namespace COMMON
{

DestroyAuthKeyOk::DestroyAuthKeyOk()
{
	this->_ConstructorID = -723427082;
}
void DestroyAuthKeyOk::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void DestroyAuthKeyOk::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
DestroyAuthKeyOk::~DestroyAuthKeyOk()
{

}
}//end namespace block
