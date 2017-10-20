#include "../Public/InputPhotoEmpty.h"


//begin namespace block
namespace COMMON
{

InputPhotoEmpty::InputPhotoEmpty()
{
	this->_ConstructorID = 483901197;
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
	this->_Responded = true;
}
InputPhotoEmpty::~InputPhotoEmpty()
{
}
}//end namespace block
