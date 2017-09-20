#include "../Public/InputStickerSetEmpty.h"


//begin namespace block
namespace COMMON
{

InputStickerSetEmpty::InputStickerSetEmpty()
{
	this->_ConstructorID = -1792297217;
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
}
InputStickerSetEmpty::~InputStickerSetEmpty()
{

}
}//end namespace block
