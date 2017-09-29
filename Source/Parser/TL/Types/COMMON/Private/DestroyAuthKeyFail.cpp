#include "../Public/DestroyAuthKeyFail.h"


//begin namespace block
namespace COMMON
{

DestroyAuthKeyFail::DestroyAuthKeyFail()
{
	this->_ConstructorID = -368010477;
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
	this->_Responded = true;
}
DestroyAuthKeyFail::~DestroyAuthKeyFail()
{

}
}//end namespace block
