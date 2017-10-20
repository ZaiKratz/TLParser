#include "../Public/KeyboardButton.h"


//begin namespace block
namespace COMMON
{

KeyboardButton::KeyboardButton()
{
	this->_ConstructorID = -1560655744;
}

KeyboardButton::KeyboardButton(FString text)
{
	this->_ConstructorID = -1560655744;
	this->text = text;
}
void KeyboardButton::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->text);
}


void KeyboardButton::OnResponce(BinaryReader& Reader)
{
	text = Reader.TGReadString();
	this->_Responded = true;
}
KeyboardButton::~KeyboardButton()
{
}
}//end namespace block
