#include "../Public/PhoneCallDiscardReasonMissed.h"


//begin namespace block
namespace COMMON
{

PhoneCallDiscardReasonMissed::PhoneCallDiscardReasonMissed()
{
	this->_ConstructorID = -2048646399;
}
void PhoneCallDiscardReasonMissed::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void PhoneCallDiscardReasonMissed::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
PhoneCallDiscardReasonMissed::~PhoneCallDiscardReasonMissed()
{
}
}//end namespace block
