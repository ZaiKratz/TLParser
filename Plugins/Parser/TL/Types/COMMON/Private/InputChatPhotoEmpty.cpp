#include "../Public/InputChatPhotoEmpty.h"


//begin namespace block
namespace COMMON
{

InputChatPhotoEmpty::InputChatPhotoEmpty()
{
	this->_ConstructorID = 1469031452;
}
void InputChatPhotoEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputChatPhotoEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
InputChatPhotoEmpty::~InputChatPhotoEmpty()
{

}
}//end namespace block
