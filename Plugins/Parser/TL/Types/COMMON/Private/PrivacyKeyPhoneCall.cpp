#include "../Public/PrivacyKeyPhoneCall.h"


//begin namespace block
namespace COMMON
{

PrivacyKeyPhoneCall::PrivacyKeyPhoneCall()
{
	this->_ConstructorID = 2066441789;
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
}
PrivacyKeyPhoneCall::~PrivacyKeyPhoneCall()
{

}
}//end namespace block
