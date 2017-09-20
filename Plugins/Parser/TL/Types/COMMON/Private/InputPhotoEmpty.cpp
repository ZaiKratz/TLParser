#include "../Public/InputPhotoEmpty.h"


//begin namespace block
namespace COMMON
{

InputPhotoEmpty::InputPhotoEmpty()
{
	this->_ConstructorID = 230676252;
}
void InputPhotoEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputPhotoEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
InputPhotoEmpty::~InputPhotoEmpty()
{

}
}//end namespace block
