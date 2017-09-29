#include "../Public/InputStickeredMediaPhoto.h"


//begin namespace block
namespace COMMON
{

InputStickeredMediaPhoto::InputStickeredMediaPhoto()
{
	this->_ConstructorID = 1251549527;
}

InputStickeredMediaPhoto::InputStickeredMediaPhoto(COMMON::InputPhoto*  id)
{
	this->_ConstructorID = 1251549527;
	this->id = id;
}
void InputStickeredMediaPhoto::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->id->OnSend(Writer);
}


void InputStickeredMediaPhoto::OnResponce(BinaryReader& Reader)
{
	id = reinterpret_cast<COMMON::InputPhoto* >(Reader.TGReadObject());
	this->_Responded = true;
}
InputStickeredMediaPhoto::~InputStickeredMediaPhoto()
{

}
}//end namespace block
