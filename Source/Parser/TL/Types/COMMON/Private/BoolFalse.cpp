#include "../Public/BoolFalse.h"


//begin namespace block
namespace COMMON
{

BoolFalse::BoolFalse()
{
	this->_ConstructorID = -1132882121;
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
	this->_Responded = true;
}
BoolFalse::~BoolFalse()
{

}
}//end namespace block
