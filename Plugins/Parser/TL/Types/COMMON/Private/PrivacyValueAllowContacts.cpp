#include "../Public/PrivacyValueAllowContacts.h"


//begin namespace block
namespace COMMON
{

PrivacyValueAllowContacts::PrivacyValueAllowContacts()
{
	this->_ConstructorID = -1407451393;
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
}
PrivacyValueAllowContacts::~PrivacyValueAllowContacts()
{

}
}//end namespace block
