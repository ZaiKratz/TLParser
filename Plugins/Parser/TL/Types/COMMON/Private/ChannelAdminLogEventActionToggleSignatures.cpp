#include "../Public/ChannelAdminLogEventActionToggleSignatures.h"


//begin namespace block
namespace COMMON
{

ChannelAdminLogEventActionToggleSignatures::ChannelAdminLogEventActionToggleSignatures()
{
	this->_ConstructorID = 1896459814;
}

ChannelAdminLogEventActionToggleSignatures::ChannelAdminLogEventActionToggleSignatures(bool new_value)
{
	this->_ConstructorID = 1896459814;
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
}
ChannelAdminLogEventActionToggleSignatures::~ChannelAdminLogEventActionToggleSignatures()
{

}
}//end namespace block