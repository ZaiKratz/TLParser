#include "../Public/InputUserEmpty.h"


//begin namespace block
namespace COMMON
{

InputUserEmpty::InputUserEmpty()
{
	this->_ConstructorID = -1182234929;
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
	this->_Responded = true;
}
InputUserEmpty::~InputUserEmpty()
{

}
}//end namespace block
