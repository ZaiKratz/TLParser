#include "../Public/PageBlockDivider.h"


//begin namespace block
namespace COMMON
{

PageBlockDivider::PageBlockDivider()
{
	this->_ConstructorID = -618614392;
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
	this->_Responded = true;
}
PageBlockDivider::~PageBlockDivider()
{

}
}//end namespace block
