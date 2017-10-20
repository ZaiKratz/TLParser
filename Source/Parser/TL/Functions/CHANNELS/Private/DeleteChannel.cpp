#include "../Public/DeleteChannel.h"


//begin namespace block
namespace CHANNELS
{

DeleteChannel::DeleteChannel()
{
	this->_ConstructorID = -1072619549;
	this->_ContentRelated = true;
}

DeleteChannel::DeleteChannel(COMMON::InputChannel*  channel)
{
	this->_ConstructorID = -1072619549;
	this->_ContentRelated = true;
	this->channel = channel;
}
void DeleteChannel::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
}


void DeleteChannel::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
	this->_Responded = true;
}
DeleteChannel::~DeleteChannel()
{
	if(this->channel)
	{
		delete this->channel;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
