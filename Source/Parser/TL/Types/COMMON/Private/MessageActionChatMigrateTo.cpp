#include "../Public/MessageActionChatMigrateTo.h"


//begin namespace block
namespace COMMON
{

MessageActionChatMigrateTo::MessageActionChatMigrateTo()
{
	this->_ConstructorID = 1371385889;
}

MessageActionChatMigrateTo::MessageActionChatMigrateTo(int32 channel_id)
{
	this->_ConstructorID = 1371385889;
	this->channel_id = channel_id;
}
void MessageActionChatMigrateTo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->channel_id);
}


void MessageActionChatMigrateTo::OnResponce(BinaryReader& Reader)
{
	channel_id = Reader.ReadInt();
	this->_Responded = true;
}
MessageActionChatMigrateTo::~MessageActionChatMigrateTo()
{
}
}//end namespace block
