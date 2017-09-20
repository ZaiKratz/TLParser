#include "../Public/MessageEntityBold.h"


//begin namespace block
namespace COMMON
{

MessageEntityBold::MessageEntityBold()
{
	this->_ConstructorID = -922000963;
}

MessageEntityBold::MessageEntityBold(int32 offset, int32 length)
{
	this->_ConstructorID = -922000963;
	this->offset = offset;
	this->length = length;
}
void MessageEntityBold::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->offset);
	Writer.WriteInt(this->length);
}


void MessageEntityBold::OnResponce(BinaryReader& Reader)
{
	offset = Reader.ReadInt();
	length = Reader.ReadInt();
}
MessageEntityBold::~MessageEntityBold()
{

}
}//end namespace block
