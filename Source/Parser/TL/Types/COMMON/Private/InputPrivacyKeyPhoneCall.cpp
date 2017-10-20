#include "../Public/InputPrivacyKeyPhoneCall.h"


//begin namespace block
namespace COMMON
{

InputPrivacyKeyPhoneCall::InputPrivacyKeyPhoneCall()
{
	this->_ConstructorID = -88417185;
}
void InputPrivacyKeyPhoneCall::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputPrivacyKeyPhoneCall::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputPrivacyKeyPhoneCall::~InputPrivacyKeyPhoneCall()
{
}
}//end namespace block
