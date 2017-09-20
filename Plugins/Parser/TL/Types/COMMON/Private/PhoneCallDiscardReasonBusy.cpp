#include "../Public/PhoneCallDiscardReasonBusy.h"


//begin namespace block
namespace COMMON
{

PhoneCallDiscardReasonBusy::PhoneCallDiscardReasonBusy()
{
	this->_ConstructorID = -907479046;
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
}
PhoneCallDiscardReasonBusy::~PhoneCallDiscardReasonBusy()
{

}
}//end namespace block
