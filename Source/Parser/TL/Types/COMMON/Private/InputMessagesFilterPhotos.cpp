#include "../Public/InputMessagesFilterPhotos.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterPhotos::InputMessagesFilterPhotos()
{
	this->_ConstructorID = -1777752804;
}
void InputMessagesFilterPhotos::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputMessagesFilterPhotos::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputMessagesFilterPhotos::~InputMessagesFilterPhotos()
{
}
}//end namespace block
