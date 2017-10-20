#include "../Public/ReadHistory.h"


//begin namespace block
namespace CHANNELS
{

ReadHistory::ReadHistory()
{
	this->_ConstructorID = -871347913;
	this->_ContentRelated = true;
}

ReadHistory::ReadHistory(COMMON::InputChannel*  channel, int32 max_id)
{
	this->_ConstructorID = -871347913;
	this->_ContentRelated = true;
	this->channel = channel;
	this->max_id = max_id;
}
void ReadHistory::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
	Writer.WriteInt(this->max_id);
}


void ReadHistory::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
ReadHistory::~ReadHistory()
{
	if(this->channel)
	{
		delete this->channel;
	}
}
}//end namespace block
