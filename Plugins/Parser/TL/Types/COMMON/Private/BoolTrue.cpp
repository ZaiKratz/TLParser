#include "../Public/BoolTrue.h"


//begin namespace block
namespace COMMON
{

BoolTrue::BoolTrue()
{
	this->_ConstructorID = -1250594151;
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
}
BoolTrue::~BoolTrue()
{

}
}//end namespace block
