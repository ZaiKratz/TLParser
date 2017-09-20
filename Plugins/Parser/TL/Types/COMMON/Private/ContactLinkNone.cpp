#include "../Public/ContactLinkNone.h"


//begin namespace block
namespace COMMON
{

ContactLinkNone::ContactLinkNone()
{
	this->_ConstructorID = -1378619906;
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
}
ContactLinkNone::~ContactLinkNone()
{

}
}//end namespace block
