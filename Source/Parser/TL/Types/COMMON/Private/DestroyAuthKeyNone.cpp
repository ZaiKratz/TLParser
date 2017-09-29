#include "../Public/DestroyAuthKeyNone.h"


//begin namespace block
namespace COMMON
{

DestroyAuthKeyNone::DestroyAuthKeyNone()
{
	this->_ConstructorID = 178201177;
}
void DestroyAuthKeyNone::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void DestroyAuthKeyNone::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
DestroyAuthKeyNone::~DestroyAuthKeyNone()
{

}
}//end namespace block
