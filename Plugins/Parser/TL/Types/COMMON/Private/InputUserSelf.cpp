#include "../Public/InputUserSelf.h"


//begin namespace block
namespace COMMON
{

InputUserSelf::InputUserSelf()
{
	this->_ConstructorID = 1068614135;
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
}
InputUserSelf::~InputUserSelf()
{

}
}//end namespace block
