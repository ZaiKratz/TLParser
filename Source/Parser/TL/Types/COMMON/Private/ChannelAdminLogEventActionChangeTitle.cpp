#include "../Public/ChannelAdminLogEventActionChangeTitle.h"


//begin namespace block
namespace COMMON
{

ChannelAdminLogEventActionChangeTitle::ChannelAdminLogEventActionChangeTitle()
{
	this->_ConstructorID = -421545947;
}

ChannelAdminLogEventActionChangeTitle::ChannelAdminLogEventActionChangeTitle(FString prev_value, FString new_value)
{
	this->_ConstructorID = -421545947;
	this->prev_value = prev_value;
	this->new_value = new_value;
}
void ChannelAdminLogEventActionChangeTitle::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->prev_value);
	Writer.TGWriteString(this->new_value);
}


void ChannelAdminLogEventActionChangeTitle::OnResponce(BinaryReader& Reader)
{
	prev_value = Reader.TGReadString();
	new_value = Reader.TGReadString();
	this->_Responded = true;
}
ChannelAdminLogEventActionChangeTitle::~ChannelAdminLogEventActionChangeTitle()
{
}
}//end namespace block
