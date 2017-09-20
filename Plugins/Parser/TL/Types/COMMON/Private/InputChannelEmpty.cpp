#include "../Public/InputChannelEmpty.h"


//begin namespace block
namespace COMMON
{

InputChannelEmpty::InputChannelEmpty()
{
	this->_ConstructorID = -2044818194;
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
}
InputChannelEmpty::~InputChannelEmpty()
{

}
}//end namespace block
