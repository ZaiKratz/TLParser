#include "../Public/InputUserEmpty.h"


//begin namespace block
namespace COMMON
{

InputUserEmpty::InputUserEmpty()
{
	this->_ConstructorID = -813266759;
}
void InputUserEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputUserEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
InputUserEmpty::~InputUserEmpty()
{

}
}//end namespace block
