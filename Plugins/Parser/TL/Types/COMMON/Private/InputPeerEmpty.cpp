#include "../Public/InputPeerEmpty.h"


//begin namespace block
namespace COMMON
{

InputPeerEmpty::InputPeerEmpty()
{
	this->_ConstructorID = -367510657;
}
void InputPeerEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputPeerEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
InputPeerEmpty::~InputPeerEmpty()
{

}
}//end namespace block
