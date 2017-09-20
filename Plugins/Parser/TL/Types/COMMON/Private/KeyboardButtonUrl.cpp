#include "../Public/KeyboardButtonUrl.h"


//begin namespace block
namespace COMMON
{

KeyboardButtonUrl::KeyboardButtonUrl()
{
	this->_ConstructorID = 100633125;
}

KeyboardButtonUrl::KeyboardButtonUrl(FString text, FString url)
{
	this->_ConstructorID = 100633125;
	this->text = text;
	this->url = url;
}
void KeyboardButtonUrl::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->text);
	Writer.TGWriteString(this->url);
}


void KeyboardButtonUrl::OnResponce(BinaryReader& Reader)
{
	text = Reader.TGReadString();
	url = Reader.TGReadString();
}
KeyboardButtonUrl::~KeyboardButtonUrl()
{

}
}//end namespace block
