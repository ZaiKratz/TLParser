#include "../Public/InputStickerSetEmpty.h"


//begin namespace block
namespace COMMON
{

InputStickerSetEmpty::InputStickerSetEmpty()
{
	this->_ConstructorID = -4838507;
}
void InputStickerSetEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputStickerSetEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputStickerSetEmpty::~InputStickerSetEmpty()
{

}
}//end namespace block
