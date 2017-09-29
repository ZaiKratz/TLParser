#include "../Public/InputPeerEmpty.h"


//begin namespace block
namespace COMMON
{

InputPeerEmpty::InputPeerEmpty()
{
	this->_ConstructorID = 2134579434;
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
	this->_Responded = true;
}
InputPeerEmpty::~InputPeerEmpty()
{

}
}//end namespace block
