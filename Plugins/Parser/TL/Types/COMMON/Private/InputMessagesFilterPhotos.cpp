#include "../Public/InputMessagesFilterPhotos.h"


//begin namespace block
namespace COMMON
{

InputMessagesFilterPhotos::InputMessagesFilterPhotos()
{
	this->_ConstructorID = 480577942;
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
}
InputMessagesFilterPhotos::~InputMessagesFilterPhotos()
{

}
}//end namespace block
