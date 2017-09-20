#include "../Public/InputPrivacyValueDisallowContacts.h"


//begin namespace block
namespace COMMON
{

InputPrivacyValueDisallowContacts::InputPrivacyValueDisallowContacts()
{
	this->_ConstructorID = 64;
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
}
InputPrivacyValueDisallowContacts::~InputPrivacyValueDisallowContacts()
{

}
}//end namespace block
