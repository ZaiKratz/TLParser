#include "../Public/DeleteUserHistory.h"


//begin namespace block
namespace CHANNELS
{

DeleteUserHistory::DeleteUserHistory()
{
	this->_ConstructorID = -787622117;
	this->_ContentRelated = true;
}

DeleteUserHistory::DeleteUserHistory(COMMON::InputChannel*  channel, COMMON::InputUser*  user_id)
{
	this->_ConstructorID = -787622117;
	this->_ContentRelated = true;
	this->channel = channel;
	this->user_id = user_id;
}
void DeleteUserHistory::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
	this->user_id->OnSend(Writer);
}


void DeleteUserHistory::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::AffectedHistory*>(Reader.TGReadObject());
	this->_Responded = true;
}
DeleteUserHistory::~DeleteUserHistory()
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
