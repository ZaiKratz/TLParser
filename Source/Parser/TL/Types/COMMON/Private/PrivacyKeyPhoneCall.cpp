#include "../Public/PrivacyKeyPhoneCall.h"


//begin namespace block
namespace COMMON
{

PrivacyKeyPhoneCall::PrivacyKeyPhoneCall()
{
	this->_ConstructorID = 1030105979;
}
void PrivacyKeyPhoneCall::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void PrivacyKeyPhoneCall::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
PrivacyKeyPhoneCall::~PrivacyKeyPhoneCall()
{
}
}//end namespace block
