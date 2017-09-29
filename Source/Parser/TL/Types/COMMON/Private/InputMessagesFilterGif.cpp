#include "../Public/InputMessagesFilterGif.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterGif::InputMessagesFilterGif()
{
	this->_ConstructorID = -3644025;
}
void InputMessagesFilterGif::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputMessagesFilterGif::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputMessagesFilterGif::~InputMessagesFilterGif()
{

}
}//end namespace block
