#include "../Public/InputPrivacyValueDisallowContacts.h"


//begin namespace block
namespace COMMON
{

InputPrivacyValueDisallowContacts::InputPrivacyValueDisallowContacts()
{
	this->_ConstructorID = 195371015;
}
void InputPrivacyValueDisallowContacts::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputPrivacyValueDisallowContacts::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputPrivacyValueDisallowContacts::~InputPrivacyValueDisallowContacts()
{

}
}//end namespace block
