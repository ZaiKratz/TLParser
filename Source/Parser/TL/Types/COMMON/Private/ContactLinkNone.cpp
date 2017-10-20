#include "../Public/ContactLinkNone.h"


//begin namespace block
namespace COMMON
{

ContactLinkNone::ContactLinkNone()
{
	this->_ConstructorID = -17968211;
}
void ContactLinkNone::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void ContactLinkNone::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
ContactLinkNone::~ContactLinkNone()
{
}
}//end namespace block
