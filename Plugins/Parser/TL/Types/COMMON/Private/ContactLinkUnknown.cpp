#include "../Public/ContactLinkUnknown.h"


//begin namespace block
namespace COMMON
{

ContactLinkUnknown::ContactLinkUnknown()
{
	this->_ConstructorID = 1200770911;
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
}
ContactLinkUnknown::~ContactLinkUnknown()
{

}
}//end namespace block
