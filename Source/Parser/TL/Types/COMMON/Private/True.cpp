#include "../Public/True.h"


//begin namespace block
namespace COMMON
{

True::True()
{
	this->_ConstructorID = 1072550713;
}
void True::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void True::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
True::~True()
{
}
}//end namespace block
