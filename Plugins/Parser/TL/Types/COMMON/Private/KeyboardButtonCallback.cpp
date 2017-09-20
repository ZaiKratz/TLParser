#include "../Public/KeyboardButtonCallback.h"


//begin namespace block
namespace COMMON
{

KeyboardButtonCallback::KeyboardButtonCallback()
{
	this->_ConstructorID = 1180580456;
}

KeyboardButtonCallback::KeyboardButtonCallback(FString text, TArray<uint8> data)
{
	this->_ConstructorID = 1180580456;
	this->text = text;
	this->data = data;
}
void KeyboardButtonCallback::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->text);
	Writer.TGWriteBytes((unsigned char*)this->data.GetData(), this->data.Num());
}


void KeyboardButtonCallback::OnResponce(BinaryReader& Reader)
{
	text = Reader.TGReadString();
	data = Reader.TGReadBytes();
}
KeyboardButtonCallback::~KeyboardButtonCallback()
{

}
}//end namespace block