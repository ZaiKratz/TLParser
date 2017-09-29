#include "../Public/DestroyAuthKeyOk.h"


//begin namespace block
namespace COMMON
{

DestroyAuthKeyOk::DestroyAuthKeyOk()
{
	this->_ConstructorID = -161422892;
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
	this->_Responded = true;
}
DestroyAuthKeyOk::~DestroyAuthKeyOk()
{

}
}//end namespace block
