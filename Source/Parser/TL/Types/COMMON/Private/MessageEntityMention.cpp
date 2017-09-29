#include "../Public/MessageEntityMention.h"


//begin namespace block
namespace COMMON
{

MessageEntityMention::MessageEntityMention()
{
	this->_ConstructorID = -100378723;
}

MessageEntityMention::MessageEntityMention(int32 offset, int32 length)
{
	this->_ConstructorID = -100378723;
	this->offset = offset;
	this->length = length;
}
void MessageEntityMention::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->offset);
	Writer.WriteInt(this->length);
}


void MessageEntityMention::OnResponce(BinaryReader& Reader)
{
	offset = Reader.ReadInt();
	length = Reader.ReadInt();
	this->_Responded = true;
}
MessageEntityMention::~MessageEntityMention()
{

}
}//end namespace block
