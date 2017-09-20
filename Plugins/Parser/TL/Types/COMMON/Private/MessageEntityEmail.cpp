#include "../Public/MessageEntityEmail.h"


//begin namespace block
namespace COMMON
{

MessageEntityEmail::MessageEntityEmail()
{
	this->_ConstructorID = -1032461212;
}

MessageEntityEmail::MessageEntityEmail(int32 offset, int32 length)
{
	this->_ConstructorID = -1032461212;
	this->offset = offset;
	this->length = length;
}
void MessageEntityEmail::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->offset);
	Writer.WriteInt(this->length);
}


void MessageEntityEmail::OnResponce(BinaryReader& Reader)
{
	offset = Reader.ReadInt();
	length = Reader.ReadInt();
}
MessageEntityEmail::~MessageEntityEmail()
{

}
}//end namespace block
