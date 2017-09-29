#include "../Public/PageBlockUnsupported.h"


//begin namespace block
namespace COMMON
{

PageBlockUnsupported::PageBlockUnsupported()
{
	this->_ConstructorID = 324435594;
}
void PageBlockUnsupported::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void PageBlockUnsupported::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
PageBlockUnsupported::~PageBlockUnsupported()
{

}
}//end namespace block
