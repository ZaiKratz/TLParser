#include "../Public/True.h"


//begin namespace block
namespace COMMON
{

True::True()
{
	this->_ConstructorID = 970190143;
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
}
True::~True()
{

}
}//end namespace block
