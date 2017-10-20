#include "../Public/InputUserSelf.h"


//begin namespace block
namespace COMMON
{

InputUserSelf::InputUserSelf()
{
	this->_ConstructorID = -138301121;
}
void InputUserSelf::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputUserSelf::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputUserSelf::~InputUserSelf()
{
}
}//end namespace block
