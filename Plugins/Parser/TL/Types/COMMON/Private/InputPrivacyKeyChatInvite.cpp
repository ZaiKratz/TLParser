#include "../Public/InputPrivacyKeyChatInvite.h"


//begin namespace block
namespace COMMON
{

InputPrivacyKeyChatInvite::InputPrivacyKeyChatInvite()
{
	this->_ConstructorID = 637860797;
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
}
InputPrivacyKeyChatInvite::~InputPrivacyKeyChatInvite()
{

}
}//end namespace block
