#include "../Public/ChannelAdminLogEventActionChangeAbout.h"


//begin namespace block
namespace COMMON
{

ChannelAdminLogEventActionChangeAbout::ChannelAdminLogEventActionChangeAbout()
{
	this->_ConstructorID = 780802133;
}

ChannelAdminLogEventActionChangeAbout::ChannelAdminLogEventActionChangeAbout(FString prev_value, FString new_value)
{
	this->_ConstructorID = 780802133;
	this->prev_value = prev_value;
	this->new_value = new_value;
}
void ChannelAdminLogEventActionChangeAbout::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->prev_value);
	Writer.TGWriteString(this->new_value);
}


void ChannelAdminLogEventActionChangeAbout::OnResponce(BinaryReader& Reader)
{
	prev_value = Reader.TGReadString();
	new_value = Reader.TGReadString();
}
ChannelAdminLogEventActionChangeAbout::~ChannelAdminLogEventActionChangeAbout()
{

}
}//end namespace block
