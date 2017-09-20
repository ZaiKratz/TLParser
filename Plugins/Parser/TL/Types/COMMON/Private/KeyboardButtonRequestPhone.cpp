#include "../Public/KeyboardButtonRequestPhone.h"


//begin namespace block
namespace COMMON
{

KeyboardButtonRequestPhone::KeyboardButtonRequestPhone()
{
	this->_ConstructorID = 694971057;
}

KeyboardButtonRequestPhone::KeyboardButtonRequestPhone(FString text)
{
	this->_ConstructorID = 694971057;
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
}
KeyboardButtonRequestPhone::~KeyboardButtonRequestPhone()
{

}
}//end namespace block
