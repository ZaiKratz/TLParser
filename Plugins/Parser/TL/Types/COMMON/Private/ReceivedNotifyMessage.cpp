#include "../Public/ReceivedNotifyMessage.h"


//begin namespace block
namespace COMMON
{

ReceivedNotifyMessage::ReceivedNotifyMessage()
{
	this->_ConstructorID = 2042070179;
}

ReceivedNotifyMessage::ReceivedNotifyMessage(int32 id, int32 flags)
{
	this->_ConstructorID = 2042070179;
	this->id = id;
	this->flags = flags;
}
void ReceivedNotifyMessage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->id);
	Writer.WriteInt(this->flags);
}


void ReceivedNotifyMessage::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadInt();
	flags = Reader.ReadInt();
}
ReceivedNotifyMessage::~ReceivedNotifyMessage()
{

}
}//end namespace block