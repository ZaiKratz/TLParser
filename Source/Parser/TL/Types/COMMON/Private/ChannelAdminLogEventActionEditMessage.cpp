#include "../Public/ChannelAdminLogEventActionEditMessage.h"


//begin namespace block
namespace COMMON
{

ChannelAdminLogEventActionEditMessage::ChannelAdminLogEventActionEditMessage()
{
	this->_ConstructorID = 1889215493;
}

ChannelAdminLogEventActionEditMessage::ChannelAdminLogEventActionEditMessage(COMMON::Message*  prev_message, COMMON::Message*  new_message)
{
	this->_ConstructorID = 1889215493;
	this->prev_message = prev_message;
	this->new_message = new_message;
}
void ChannelAdminLogEventActionEditMessage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->prev_message->OnSend(Writer);
	this->new_message->OnSend(Writer);
}


void ChannelAdminLogEventActionEditMessage::OnResponce(BinaryReader& Reader)
{
	prev_message = reinterpret_cast<COMMON::Message* >(Reader.TGReadObject());
	new_message = reinterpret_cast<COMMON::Message* >(Reader.TGReadObject());
	this->_Responded = true;
}
ChannelAdminLogEventActionEditMessage::~ChannelAdminLogEventActionEditMessage()
{

}
}//end namespace block
