#include "../Public/ContactLinkHasPhone.h"


//begin namespace block
namespace COMMON
{

ContactLinkHasPhone::ContactLinkHasPhone()
{
	this->_ConstructorID = 1497337638;
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
}
ContactLinkHasPhone::~ContactLinkHasPhone()
{

}
}//end namespace block
