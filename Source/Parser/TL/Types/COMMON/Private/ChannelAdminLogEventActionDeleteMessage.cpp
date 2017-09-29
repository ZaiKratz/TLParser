#include "../Public/ChannelAdminLogEventActionDeleteMessage.h"


//begin namespace block
namespace COMMON
{

ChannelAdminLogEventActionDeleteMessage::ChannelAdminLogEventActionDeleteMessage()
{
	this->_ConstructorID = 1121994683;
}

ChannelAdminLogEventActionDeleteMessage::ChannelAdminLogEventActionDeleteMessage(COMMON::Message*  message)
{
	this->_ConstructorID = 1121994683;
	this->message = message;
}
void ChannelAdminLogEventActionDeleteMessage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->message->OnSend(Writer);
}


void ChannelAdminLogEventActionDeleteMessage::OnResponce(BinaryReader& Reader)
{
	message = reinterpret_cast<COMMON::Message* >(Reader.TGReadObject());
	this->_Responded = true;
}
ChannelAdminLogEventActionDeleteMessage::~ChannelAdminLogEventActionDeleteMessage()
{

}
}//end namespace block
