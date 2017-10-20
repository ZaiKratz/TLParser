#include "../Public/PrivacyValueAllowContacts.h"


//begin namespace block
namespace COMMON
{

PrivacyValueAllowContacts::PrivacyValueAllowContacts()
{
	this->_ConstructorID = -123988;
}
void PrivacyValueAllowContacts::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void PrivacyValueAllowContacts::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
PrivacyValueAllowContacts::~PrivacyValueAllowContacts()
{
}
}//end namespace block
