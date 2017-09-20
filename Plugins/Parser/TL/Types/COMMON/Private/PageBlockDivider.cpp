#include "../Public/PageBlockDivider.h"


//begin namespace block
namespace COMMON
{

PageBlockDivider::PageBlockDivider()
{
	this->_ConstructorID = -2001657637;
}
void PageBlockDivider::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void PageBlockDivider::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
PageBlockDivider::~PageBlockDivider()
{

}
}//end namespace block
