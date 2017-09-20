#include "../Public/InputMessagesFilterGif.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterGif::InputMessagesFilterGif()
{
	this->_ConstructorID = -2023372545;
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
}
InputMessagesFilterGif::~InputMessagesFilterGif()
{

}
}//end namespace block
