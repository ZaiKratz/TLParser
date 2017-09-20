#include "../Public/InputMediaGifExternal.h"


//begin namespace block
namespace COMMON
{

InputMediaGifExternal::InputMediaGifExternal()
{
	this->_ConstructorID = -38780088;
}

InputMediaGifExternal::InputMediaGifExternal(FString url, FString q)
{
	this->_ConstructorID = -38780088;
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
}
InputMediaGifExternal::~InputMediaGifExternal()
{

}
}//end namespace block
