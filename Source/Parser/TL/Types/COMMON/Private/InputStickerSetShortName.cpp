#include "../Public/InputStickerSetShortName.h"


//begin namespace block
namespace COMMON
{

InputStickerSetShortName::InputStickerSetShortName()
{
	this->_ConstructorID = -2044933984;
}

InputStickerSetShortName::InputStickerSetShortName(FString short_name)
{
	this->_ConstructorID = -2044933984;
	this->short_name = short_name;
}
void InputStickerSetShortName::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->short_name);
}


void InputStickerSetShortName::OnResponce(BinaryReader& Reader)
{
	short_name = Reader.TGReadString();
	this->_Responded = true;
}
InputStickerSetShortName::~InputStickerSetShortName()
{
}
}//end namespace block
