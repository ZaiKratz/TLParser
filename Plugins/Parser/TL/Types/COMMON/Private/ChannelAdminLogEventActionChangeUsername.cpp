#include "../Public/ChannelAdminLogEventActionChangeUsername.h"


//begin namespace block
namespace COMMON
{

ChannelAdminLogEventActionChangeUsername::ChannelAdminLogEventActionChangeUsername()
{
	this->_ConstructorID = 956058218;
}

ChannelAdminLogEventActionChangeUsername::ChannelAdminLogEventActionChangeUsername(FString prev_value, FString new_value)
{
	this->_ConstructorID = 956058218;
	this->prev_value = prev_value;
	this->new_value = new_value;
}
void ChannelAdminLogEventActionChangeUsername::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->prev_value);
	Writer.TGWriteString(this->new_value);
}


void ChannelAdminLogEventActionChangeUsername::OnResponce(BinaryReader& Reader)
{
	prev_value = Reader.TGReadString();
	new_value = Reader.TGReadString();
}
ChannelAdminLogEventActionChangeUsername::~ChannelAdminLogEventActionChangeUsername()
{

}
}//end namespace block
