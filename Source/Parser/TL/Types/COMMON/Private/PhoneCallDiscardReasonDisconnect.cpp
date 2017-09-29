#include "../Public/PhoneCallDiscardReasonDisconnect.h"


//begin namespace block
namespace COMMON
{

PhoneCallDiscardReasonDisconnect::PhoneCallDiscardReasonDisconnect()
{
	this->_ConstructorID = -527056480;
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
	this->_Responded = true;
}
PhoneCallDiscardReasonDisconnect::~PhoneCallDiscardReasonDisconnect()
{

}
}//end namespace block
