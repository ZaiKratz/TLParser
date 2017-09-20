#include "../Public/DraftMessageEmpty.h"


//begin namespace block
namespace COMMON
{

DraftMessageEmpty::DraftMessageEmpty()
{
	this->_ConstructorID = -978433094;
}
void DraftMessageEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void DraftMessageEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
DraftMessageEmpty::~DraftMessageEmpty()
{

}
}//end namespace block
