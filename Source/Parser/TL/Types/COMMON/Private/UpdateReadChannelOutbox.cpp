#include "../Public/UpdateReadChannelOutbox.h"


//begin namespace block
namespace COMMON
{

UpdateReadChannelOutbox::UpdateReadChannelOutbox()
{
	this->_ConstructorID = 634833351;
}

UpdateReadChannelOutbox::UpdateReadChannelOutbox(int32 channel_id, int32 max_id)
{
	this->_ConstructorID = 634833351;
	this->channel_id = channel_id;
	this->max_id = max_id;
}
void UpdateReadChannelOutbox::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->channel_id);
	Writer.WriteInt(this->max_id);
}


void UpdateReadChannelOutbox::OnResponce(BinaryReader& Reader)
{
	channel_id = Reader.ReadInt();
	max_id = Reader.ReadInt();
	this->_Responded = true;
}
UpdateReadChannelOutbox::~UpdateReadChannelOutbox()
{

}
}//end namespace block
