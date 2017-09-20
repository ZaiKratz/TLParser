#include "../Public/ChannelAdminLogEventActionUpdatePinned.h"


//begin namespace block
namespace COMMON
{

ChannelAdminLogEventActionUpdatePinned::ChannelAdminLogEventActionUpdatePinned()
{
	this->_ConstructorID = 405596393;
}

ChannelAdminLogEventActionUpdatePinned::ChannelAdminLogEventActionUpdatePinned(COMMON::Message* message)
{
	this->_ConstructorID = 405596393;
	this->message = message;
}
void ChannelAdminLogEventActionUpdatePinned::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->message->OnSend(Writer);
}


void ChannelAdminLogEventActionUpdatePinned::OnResponce(BinaryReader& Reader)
{
	message = reinterpret_cast<COMMON::Message*>(Reader.TGReadObject());
}
ChannelAdminLogEventActionUpdatePinned::~ChannelAdminLogEventActionUpdatePinned()
{

}
}//end namespace block
