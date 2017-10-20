#include "../Public/Null.h"


//begin namespace block
namespace COMMON
{

Null::Null()
{
	this->_ConstructorID = 1450380236;
}
void Null::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void Null::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
Null::~Null()
{
}
}//end namespace block
