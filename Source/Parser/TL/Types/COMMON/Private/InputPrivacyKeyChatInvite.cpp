#include "../Public/InputPrivacyKeyChatInvite.h"


//begin namespace block
namespace COMMON
{

InputPrivacyKeyChatInvite::InputPrivacyKeyChatInvite()
{
	this->_ConstructorID = -1107622874;
}
void InputPrivacyKeyChatInvite::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputPrivacyKeyChatInvite::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputPrivacyKeyChatInvite::~InputPrivacyKeyChatInvite()
{

}
}//end namespace block
