#include "../Public/ChannelAdminLogEventActionUpdatePinned.h"


//begin namespace block
namespace COMMON
{

ChannelAdminLogEventActionUpdatePinned::ChannelAdminLogEventActionUpdatePinned()
{
	this->_ConstructorID = -370660328;
}

ChannelAdminLogEventActionUpdatePinned::ChannelAdminLogEventActionUpdatePinned(COMMON::Message*  message)
{
	this->_ConstructorID = -370660328;
	this->message = message;
}
void ChannelAdminLogEventActionUpdatePinned::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->message->OnSend(Writer);
}


void ChannelAdminLogEventActionUpdatePinned::OnResponce(BinaryReader& Reader)
{
	message = reinterpret_cast<COMMON::Message* >(Reader.TGReadObject());
	this->_Responded = true;
}
ChannelAdminLogEventActionUpdatePinned::~ChannelAdminLogEventActionUpdatePinned()
{
	if(this->message)
	{
		delete this->message;
	}
}
}//end namespace block
