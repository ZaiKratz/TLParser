#include "../Public/ContactLinkHasPhone.h"


//begin namespace block
namespace COMMON
{

ContactLinkHasPhone::ContactLinkHasPhone()
{
	this->_ConstructorID = 646922073;
}
void ContactLinkHasPhone::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void ContactLinkHasPhone::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
ContactLinkHasPhone::~ContactLinkHasPhone()
{
}
}//end namespace block
