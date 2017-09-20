#include "../Public/MessageEntityUrl.h"


//begin namespace block
namespace COMMON
{

MessageEntityUrl::MessageEntityUrl()
{
	this->_ConstructorID = 942002286;
}

MessageEntityUrl::MessageEntityUrl(int32 offset, int32 length)
{
	this->_ConstructorID = 942002286;
	this->offset = offset;
	this->length = length;
}
void MessageEntityUrl::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->offset);
	Writer.WriteInt(this->length);
}


void MessageEntityUrl::OnResponce(BinaryReader& Reader)
{
	offset = Reader.ReadInt();
	length = Reader.ReadInt();
}
MessageEntityUrl::~MessageEntityUrl()
{

}
}//end namespace block
