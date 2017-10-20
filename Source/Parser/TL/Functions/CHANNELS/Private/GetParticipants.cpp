#include "../Public/GetParticipants.h"


//begin namespace block
namespace CHANNELS
{

GetParticipants::GetParticipants()
{
	this->_ConstructorID = 618237842;
	this->_ContentRelated = true;
}

GetParticipants::GetParticipants(COMMON::InputChannel*  channel, TLBaseObject*  filter, int32 offset, int32 limit)
{
	this->_ConstructorID = 618237842;
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
	this->_Responded = true;
}
GetParticipants::~GetParticipants()
{
	if(this->channel)
	{
		delete this->channel;
	}
	if(this->filter)
	{
		delete this->filter;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
