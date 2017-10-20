#include "../Public/ChannelAdminLogEventActionToggleInvites.h"


//begin namespace block
namespace COMMON
{

ChannelAdminLogEventActionToggleInvites::ChannelAdminLogEventActionToggleInvites()
{
	this->_ConstructorID = 460916654;
}

ChannelAdminLogEventActionToggleInvites::ChannelAdminLogEventActionToggleInvites(bool new_value)
{
	this->_ConstructorID = 460916654;
	this->new_value = new_value;
}
void ChannelAdminLogEventActionToggleInvites::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteBool(this->new_value);
}


void ChannelAdminLogEventActionToggleInvites::OnResponce(BinaryReader& Reader)
{
	new_value = Reader.ReadBool();
	this->_Responded = true;
}
ChannelAdminLogEventActionToggleInvites::~ChannelAdminLogEventActionToggleInvites()
{
}
}//end namespace block
