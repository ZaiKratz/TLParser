#include "../Public/PageBlockUnsupported.h"


//begin namespace block
namespace COMMON
{

PageBlockUnsupported::PageBlockUnsupported()
{
	this->_ConstructorID = -1971431917;
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
}
PageBlockUnsupported::~PageBlockUnsupported()
{

}
}//end namespace block
