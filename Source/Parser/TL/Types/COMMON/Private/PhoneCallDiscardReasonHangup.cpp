#include "../Public/PhoneCallDiscardReasonHangup.h"


//begin namespace block
namespace COMMON
{

PhoneCallDiscardReasonHangup::PhoneCallDiscardReasonHangup()
{
	this->_ConstructorID = 1471006352;
}
void PhoneCallDiscardReasonHangup::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void PhoneCallDiscardReasonHangup::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
PhoneCallDiscardReasonHangup::~PhoneCallDiscardReasonHangup()
{
}
}//end namespace block
