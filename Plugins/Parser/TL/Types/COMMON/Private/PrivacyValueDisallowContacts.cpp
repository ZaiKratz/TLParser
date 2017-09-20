#include "../Public/PrivacyValueDisallowContacts.h"


//begin namespace block
namespace COMMON
{

PrivacyValueDisallowContacts::PrivacyValueDisallowContacts()
{
	this->_ConstructorID = 452626680;
}
void PrivacyValueDisallowContacts::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void PrivacyValueDisallowContacts::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
PrivacyValueDisallowContacts::~PrivacyValueDisallowContacts()
{

}
}//end namespace block
