#include "../Public/MessageEntityBotCommand.h"


//begin namespace block
namespace COMMON
{

MessageEntityBotCommand::MessageEntityBotCommand()
{
	this->_ConstructorID = 1827637959;
}

MessageEntityBotCommand::MessageEntityBotCommand(int32 offset, int32 length)
{
	this->_ConstructorID = 1827637959;
	this->offset = offset;
	this->length = length;
}
void MessageEntityBotCommand::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->offset);
	Writer.WriteInt(this->length);
}


void MessageEntityBotCommand::OnResponce(BinaryReader& Reader)
{
	offset = Reader.ReadInt();
	length = Reader.ReadInt();
	this->_Responded = true;
}
MessageEntityBotCommand::~MessageEntityBotCommand()
{
}
}//end namespace block
