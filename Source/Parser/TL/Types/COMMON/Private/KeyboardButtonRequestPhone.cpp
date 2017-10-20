#include "../Public/KeyboardButtonRequestPhone.h"


//begin namespace block
namespace COMMON
{

KeyboardButtonRequestPhone::KeyboardButtonRequestPhone()
{
	this->_ConstructorID = -1318425559;
}

KeyboardButtonRequestPhone::KeyboardButtonRequestPhone(FString text)
{
	this->_ConstructorID = -1318425559;
	this->text = text;
}
void KeyboardButtonRequestPhone::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->text);
}


void KeyboardButtonRequestPhone::OnResponce(BinaryReader& Reader)
{
	text = Reader.TGReadString();
	this->_Responded = true;
}
KeyboardButtonRequestPhone::~KeyboardButtonRequestPhone()
{
}
}//end namespace block
