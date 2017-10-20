#include "../Public/KeyboardButtonBuy.h"


//begin namespace block
namespace COMMON
{

KeyboardButtonBuy::KeyboardButtonBuy()
{
	this->_ConstructorID = -1344716869;
}

KeyboardButtonBuy::KeyboardButtonBuy(FString text)
{
	this->_ConstructorID = -1344716869;
	this->text = text;
}
void KeyboardButtonBuy::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->text);
}


void KeyboardButtonBuy::OnResponce(BinaryReader& Reader)
{
	text = Reader.TGReadString();
	this->_Responded = true;
}
KeyboardButtonBuy::~KeyboardButtonBuy()
{
}
}//end namespace block
