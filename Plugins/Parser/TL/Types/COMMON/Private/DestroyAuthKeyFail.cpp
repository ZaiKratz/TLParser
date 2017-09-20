#include "../Public/DestroyAuthKeyFail.h"


//begin namespace block
namespace COMMON
{

DestroyAuthKeyFail::DestroyAuthKeyFail()
{
	this->_ConstructorID = 328929514;
}
void DestroyAuthKeyFail::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void DestroyAuthKeyFail::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
DestroyAuthKeyFail::~DestroyAuthKeyFail()
{

}
}//end namespace block
