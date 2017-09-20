#include "../Public/MessageEntityHashtag.h"


//begin namespace block
namespace COMMON
{

MessageEntityHashtag::MessageEntityHashtag()
{
	this->_ConstructorID = 224093039;
}

MessageEntityHashtag::MessageEntityHashtag(int32 offset, int32 length)
{
	this->_ConstructorID = 224093039;
	this->offset = offset;
	this->length = length;
}
void MessageEntityHashtag::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->offset);
	Writer.WriteInt(this->length);
}


void MessageEntityHashtag::OnResponce(BinaryReader& Reader)
{
	offset = Reader.ReadInt();
	length = Reader.ReadInt();
}
MessageEntityHashtag::~MessageEntityHashtag()
{

}
}//end namespace block
