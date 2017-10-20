#include "../Public/BoolTrue.h"


//begin namespace block
namespace COMMON
{

BoolTrue::BoolTrue()
{
	this->_ConstructorID = -1720552011;
}
void BoolTrue::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void BoolTrue::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
BoolTrue::~BoolTrue()
{
}
}//end namespace block
