#include "../Public/InputPrivacyKeyPhoneCall.h"


//begin namespace block
namespace COMMON
{

InputPrivacyKeyPhoneCall::InputPrivacyKeyPhoneCall()
{
	this->_ConstructorID = 1608301306;
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
}
InputPrivacyKeyPhoneCall::~InputPrivacyKeyPhoneCall()
{

}
}//end namespace block
