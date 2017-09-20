#include "../Public/MessageEntityMentionName.h"


//begin namespace block
namespace COMMON
{

MessageEntityMentionName::MessageEntityMentionName()
{
	this->_ConstructorID = 1489644853;
}

MessageEntityMentionName::MessageEntityMentionName(int32 offset, int32 length, int32 user_id)
{
	this->_ConstructorID = 1489644853;
	this->offset = offset;
	this->length = length;
	this->user_id = user_id;
}
void MessageEntityMentionName::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->offset);
	Writer.WriteInt(this->length);
	Writer.WriteInt(this->user_id);
}


void MessageEntityMentionName::OnResponce(BinaryReader& Reader)
{
	offset = Reader.ReadInt();
	length = Reader.ReadInt();
	user_id = Reader.ReadInt();
}
MessageEntityMentionName::~MessageEntityMentionName()
{

}
}//end namespace block
