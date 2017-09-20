#include "../Public/ContactLinkContact.h"


//begin namespace block
namespace COMMON
{

ContactLinkContact::ContactLinkContact()
{
	this->_ConstructorID = -792591659;
}
void ContactLinkContact::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void ContactLinkContact::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
ContactLinkContact::~ContactLinkContact()
{

}
}//end namespace block
