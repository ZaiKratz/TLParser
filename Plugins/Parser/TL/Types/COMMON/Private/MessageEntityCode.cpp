#include "../Public/MessageEntityCode.h"


//begin namespace block
namespace COMMON
{

MessageEntityCode::MessageEntityCode()
{
	this->_ConstructorID = 1896194600;
}

MessageEntityCode::MessageEntityCode(int32 offset, int32 length)
{
	this->_ConstructorID = 1896194600;
	this->offset = offset;
	this->length = length;
}
void MessageEntityCode::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->offset);
	Writer.WriteInt(this->length);
}


void MessageEntityCode::OnResponce(BinaryReader& Reader)
{
	offset = Reader.ReadInt();
	length = Reader.ReadInt();
}
MessageEntityCode::~MessageEntityCode()
{

}
}//end namespace block
