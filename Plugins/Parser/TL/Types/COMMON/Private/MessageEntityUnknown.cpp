#include "../Public/MessageEntityUnknown.h"


//begin namespace block
namespace COMMON
{

MessageEntityUnknown::MessageEntityUnknown()
{
	this->_ConstructorID = -1782934853;
}

MessageEntityUnknown::MessageEntityUnknown(int32 offset, int32 length)
{
	this->_ConstructorID = -1782934853;
	this->offset = offset;
	this->length = length;
}
void MessageEntityUnknown::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->offset);
	Writer.WriteInt(this->length);
}


void MessageEntityUnknown::OnResponce(BinaryReader& Reader)
{
	offset = Reader.ReadInt();
	length = Reader.ReadInt();
}
MessageEntityUnknown::~MessageEntityUnknown()
{

}
}//end namespace block
