#include "../Public/ChannelAdminLogEventActionToggleSignatures.h"


//begin namespace block
namespace COMMON
{

ChannelAdminLogEventActionToggleSignatures::ChannelAdminLogEventActionToggleSignatures()
{
	this->_ConstructorID = 648939889;
}

ChannelAdminLogEventActionToggleSignatures::ChannelAdminLogEventActionToggleSignatures(bool new_value)
{
	this->_ConstructorID = 648939889;
	this->new_value = new_value;
}
void ChannelAdminLogEventActionToggleSignatures::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteBool(this->new_value);
}


void ChannelAdminLogEventActionToggleSignatures::OnResponce(BinaryReader& Reader)
{
	new_value = Reader.ReadBool();
	this->_Responded = true;
}
ChannelAdminLogEventActionToggleSignatures::~ChannelAdminLogEventActionToggleSignatures()
{
}
}//end namespace block
