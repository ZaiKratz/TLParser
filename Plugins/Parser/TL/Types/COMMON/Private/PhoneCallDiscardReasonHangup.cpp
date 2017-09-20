#include "../Public/PhoneCallDiscardReasonHangup.h"


//begin namespace block
namespace COMMON
{

PhoneCallDiscardReasonHangup::PhoneCallDiscardReasonHangup()
{
	this->_ConstructorID = -1866027689;
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
}
PhoneCallDiscardReasonHangup::~PhoneCallDiscardReasonHangup()
{

}
}//end namespace block
