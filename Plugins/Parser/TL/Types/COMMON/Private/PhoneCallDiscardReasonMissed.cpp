#include "../Public/PhoneCallDiscardReasonMissed.h"


//begin namespace block
namespace COMMON
{

PhoneCallDiscardReasonMissed::PhoneCallDiscardReasonMissed()
{
	this->_ConstructorID = 19129477;
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
}
PhoneCallDiscardReasonMissed::~PhoneCallDiscardReasonMissed()
{

}
}//end namespace block
