#include "../Public/InputChannelEmpty.h"


//begin namespace block
namespace COMMON
{

InputChannelEmpty::InputChannelEmpty()
{
	this->_ConstructorID = -292807034;
}
void InputChannelEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputChannelEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputChannelEmpty::~InputChannelEmpty()
{

}
}//end namespace block
