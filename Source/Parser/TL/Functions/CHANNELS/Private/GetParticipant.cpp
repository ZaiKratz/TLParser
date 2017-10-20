#include "../Public/GetParticipant.h"


//begin namespace block
namespace CHANNELS
{

GetParticipant::GetParticipant()
{
	this->_ConstructorID = 1416484774;
	this->_ContentRelated = true;
}

GetParticipant::GetParticipant(COMMON::InputChannel*  channel, COMMON::InputUser*  user_id)
{
	this->_ConstructorID = 1416484774;
	this->_ContentRelated = true;
	this->channel = channel;
	this->user_id = user_id;
}
void GetParticipant::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
	this->user_id->OnSend(Writer);
}


void GetParticipant::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<CHANNELS::ChannelParticipant*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetParticipant::~GetParticipant()
{
	if(this->channel)
	{
		delete this->channel;
	}
	if(this->user_id)
	{
		delete this->user_id;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
