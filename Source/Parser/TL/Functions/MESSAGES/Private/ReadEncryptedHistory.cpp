#include "../Public/ReadEncryptedHistory.h"


//begin namespace block
namespace MESSAGES
{

ReadEncryptedHistory::ReadEncryptedHistory()
{
	this->_ConstructorID = 2135648522;
	this->_ContentRelated = true;
}

ReadEncryptedHistory::ReadEncryptedHistory(COMMON::InputEncryptedChat*  peer, FDateTime max_date)
{
	this->_ConstructorID = 2135648522;
	this->_ContentRelated = true;
	this->peer = peer;
	this->max_date = max_date;
}
void ReadEncryptedHistory::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	Writer.TGWriteDate(this->max_date);
}


void ReadEncryptedHistory::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
ReadEncryptedHistory::~ReadEncryptedHistory()
{
	if(this->peer)
	{
		delete this->peer;
	}
}
}//end namespace block
