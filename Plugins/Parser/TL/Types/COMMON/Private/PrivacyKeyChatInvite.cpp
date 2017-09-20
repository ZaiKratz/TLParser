#include "../Public/PrivacyKeyChatInvite.h"


//begin namespace block
namespace COMMON
{

PrivacyKeyChatInvite::PrivacyKeyChatInvite()
{
	this->_ConstructorID = -93516208;
}
void PrivacyKeyChatInvite::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void PrivacyKeyChatInvite::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
PrivacyKeyChatInvite::~PrivacyKeyChatInvite()
{

}
}//end namespace block
