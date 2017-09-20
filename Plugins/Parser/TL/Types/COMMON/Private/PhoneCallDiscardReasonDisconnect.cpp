#include "../Public/PhoneCallDiscardReasonDisconnect.h"


//begin namespace block
namespace COMMON
{

PhoneCallDiscardReasonDisconnect::PhoneCallDiscardReasonDisconnect()
{
	this->_ConstructorID = -1597925920;
}
void PhoneCallDiscardReasonDisconnect::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void PhoneCallDiscardReasonDisconnect::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
PhoneCallDiscardReasonDisconnect::~PhoneCallDiscardReasonDisconnect()
{

}
}//end namespace block
