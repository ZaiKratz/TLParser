#include "../Public/InputMediaGifExternal.h"


//begin namespace block
namespace COMMON
{

InputMediaGifExternal::InputMediaGifExternal()
{
	this->_ConstructorID = 1212395773;
}

InputMediaGifExternal::InputMediaGifExternal(FString url, FString q)
{
	this->_ConstructorID = 1212395773;
	this->url = url;
	this->q = q;
}
void InputMediaGifExternal::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->url);
	Writer.TGWriteString(this->q);
}


void InputMediaGifExternal::OnResponce(BinaryReader& Reader)
{
	url = Reader.TGReadString();
	q = Reader.TGReadString();
	this->_Responded = true;
}
InputMediaGifExternal::~InputMediaGifExternal()
{

}
}//end namespace block
