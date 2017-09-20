#include "../Public/InputPrivacyValueAllowContacts.h"


//begin namespace block
namespace COMMON
{

InputPrivacyValueAllowContacts::InputPrivacyValueAllowContacts()
{
	this->_ConstructorID = 64;
}
void InputPrivacyValueAllowContacts::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputPrivacyValueAllowContacts::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
InputPrivacyValueAllowContacts::~InputPrivacyValueAllowContacts()
{

}
}//end namespace block
