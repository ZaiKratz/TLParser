#include "../Public/DestroyAuthKeyNone.h"


//begin namespace block
namespace COMMON
{

DestroyAuthKeyNone::DestroyAuthKeyNone()
{
	this->_ConstructorID = 1495441162;
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
}
DestroyAuthKeyNone::~DestroyAuthKeyNone()
{

}
}//end namespace block
