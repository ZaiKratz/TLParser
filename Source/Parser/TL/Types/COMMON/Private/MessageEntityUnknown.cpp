#include "../Public/MessageEntityUnknown.h"


//begin namespace block
namespace COMMON
{

MessageEntityUnknown::MessageEntityUnknown()
{
	this->_ConstructorID = -1148011883;
}

MessageEntityUnknown::MessageEntityUnknown(int32 offset, int32 length)
{
	this->_ConstructorID = -1148011883;
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
	this->_Responded = true;
}
MessageEntityUnknown::~MessageEntityUnknown()
{
}
}//end namespace block
