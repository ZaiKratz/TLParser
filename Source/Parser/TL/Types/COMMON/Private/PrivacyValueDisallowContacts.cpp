#include "../Public/PrivacyValueDisallowContacts.h"


//begin namespace block
namespace COMMON
{

PrivacyValueDisallowContacts::PrivacyValueDisallowContacts()
{
	this->_ConstructorID = -125240806;
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
	this->_Responded = true;
}
PrivacyValueDisallowContacts::~PrivacyValueDisallowContacts()
{
}
}//end namespace block
