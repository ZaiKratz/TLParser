#include "../Public/MessageEntityTextUrl.h"


//begin namespace block
namespace COMMON
{

MessageEntityTextUrl::MessageEntityTextUrl()
{
	this->_ConstructorID = 668182134;
}

MessageEntityTextUrl::MessageEntityTextUrl(int32 offset, int32 length, FString url)
{
	this->_ConstructorID = 668182134;
	this->offset = offset;
	this->length = length;
	this->url = url;
}
void MessageEntityTextUrl::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->offset);
	Writer.WriteInt(this->length);
	Writer.TGWriteString(this->url);
}


void MessageEntityTextUrl::OnResponce(BinaryReader& Reader)
{
	offset = Reader.ReadInt();
	length = Reader.ReadInt();
	url = Reader.TGReadString();
}
MessageEntityTextUrl::~MessageEntityTextUrl()
{

}
}//end namespace block
