#include "../Public/MessageActionChannelMigrateFrom.h"


//begin namespace block
namespace COMMON
{

MessageActionChannelMigrateFrom::MessageActionChannelMigrateFrom()
{
	this->_ConstructorID = -1336546578;
}

MessageActionChannelMigrateFrom::MessageActionChannelMigrateFrom(FString title, int32 chat_id)
{
	this->_ConstructorID = -1336546578;
	this->title = title;
	this->chat_id = chat_id;
}
void MessageActionChannelMigrateFrom::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->title);
	Writer.WriteInt(this->chat_id);
}


void MessageActionChannelMigrateFrom::OnResponce(BinaryReader& Reader)
{
	title = Reader.TGReadString();
	chat_id = Reader.ReadInt();
	this->_Responded = true;
}
MessageActionChannelMigrateFrom::~MessageActionChannelMigrateFrom()
{

}
}//end namespace block
