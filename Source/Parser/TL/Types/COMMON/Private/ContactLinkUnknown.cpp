#include "../Public/ContactLinkUnknown.h"


//begin namespace block
namespace COMMON
{

ContactLinkUnknown::ContactLinkUnknown()
{
	this->_ConstructorID = 1599050311;
}
void ContactLinkUnknown::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void ContactLinkUnknown::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
ContactLinkUnknown::~ContactLinkUnknown()
{
}
}//end namespace block
