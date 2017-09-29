#include "../Public/MessageEntityItalic.h"


//begin namespace block
namespace COMMON
{

MessageEntityItalic::MessageEntityItalic()
{
	this->_ConstructorID = -2106619040;
}

MessageEntityItalic::MessageEntityItalic(int32 offset, int32 length)
{
	this->_ConstructorID = -2106619040;
	this->offset = offset;
	this->length = length;
}
void MessageEntityItalic::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->offset);
	Writer.WriteInt(this->length);
}


void MessageEntityItalic::OnResponce(BinaryReader& Reader)
{
	offset = Reader.ReadInt();
	length = Reader.ReadInt();
	this->_Responded = true;
}
MessageEntityItalic::~MessageEntityItalic()
{

}
}//end namespace block
