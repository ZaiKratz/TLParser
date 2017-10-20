#include "../Public/DraftMessageEmpty.h"


//begin namespace block
namespace COMMON
{

DraftMessageEmpty::DraftMessageEmpty()
{
	this->_ConstructorID = -1169445179;
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
	this->_Responded = true;
}
DraftMessageEmpty::~DraftMessageEmpty()
{
}
}//end namespace block
