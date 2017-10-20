#include "../Public/ReadHistory.h"


//begin namespace block
namespace MESSAGES
{

ReadHistory::ReadHistory()
{
	this->_ConstructorID = 238054714;
	this->_ContentRelated = true;
}

ReadHistory::ReadHistory(TLBaseObject*  peer, int32 max_id)
{
	this->_ConstructorID = 238054714;
	this->_ContentRelated = true;
	this->peer = peer;
	this->max_id = max_id;
}
void ReadHistory::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	Writer.WriteInt(this->max_id);
}


void ReadHistory::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::AffectedMessages*>(Reader.TGReadObject());
	this->_Responded = true;
}
ReadHistory::~ReadHistory()
{
	if(this->peer)
	{
		delete this->peer;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
