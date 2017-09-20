#include "../Public/BoolFalse.h"


//begin namespace block
namespace COMMON
{

BoolFalse::BoolFalse()
{
	this->_ConstructorID = 932673980;
}
void BoolFalse::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void BoolFalse::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
BoolFalse::~BoolFalse()
{

}
}//end namespace block
