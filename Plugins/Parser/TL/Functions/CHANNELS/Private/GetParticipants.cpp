#include "../Public/GetParticipants.h"


//begin namespace block
namespace CHANNELS
{

GetParticipants::GetParticipants()
{
	this->_ConstructorID = -1836066524;
	this->_ContentRelated = true;
}

GetParticipants::GetParticipants(COMMON::InputChannel* channel, PRIVATE::ChannelParticipantsFilter* filter, int32 offset, int32 limit)
{
	this->_ConstructorID = -1836066524;
	this->_ContentRelated = true;
	this->channel = channel;
	this->filter = filter;
	this->offset = offset;
	this->limit = limit;
}
void GetParticipants::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
	this->filter->OnSend(Writer);
	Writer.WriteInt(this->offset);
	Writer.WriteInt(this->limit);
}


void GetParticipants::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<CHANNELS::ChannelParticipants*>(Reader.TGReadObject());
}
GetParticipants::~GetParticipants()
{

}
}//end namespace block
