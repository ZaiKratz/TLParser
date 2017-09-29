#include "../Public/PhoneCallDiscardReasonBusy.h"


//begin namespace block
namespace COMMON
{

PhoneCallDiscardReasonBusy::PhoneCallDiscardReasonBusy()
{
	this->_ConstructorID = -84416311;
}
void PhoneCallDiscardReasonBusy::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void PhoneCallDiscardReasonBusy::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
PhoneCallDiscardReasonBusy::~PhoneCallDiscardReasonBusy()
{

}
}//end namespace block
