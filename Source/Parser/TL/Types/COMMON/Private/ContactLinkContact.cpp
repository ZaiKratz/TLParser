#include "../Public/ContactLinkContact.h"


//begin namespace block
namespace COMMON
{

ContactLinkContact::ContactLinkContact()
{
	this->_ConstructorID = -721239344;
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
	this->_Responded = true;
}
ContactLinkContact::~ContactLinkContact()
{

}
}//end namespace block
