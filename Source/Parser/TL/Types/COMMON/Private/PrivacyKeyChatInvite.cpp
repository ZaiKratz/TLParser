#include "../Public/PrivacyKeyChatInvite.h"


//begin namespace block
namespace COMMON
{

PrivacyKeyChatInvite::PrivacyKeyChatInvite()
{
	this->_ConstructorID = 1343122938;
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
	this->_Responded = true;
}
PrivacyKeyChatInvite::~PrivacyKeyChatInvite()
{

}
}//end namespace block
