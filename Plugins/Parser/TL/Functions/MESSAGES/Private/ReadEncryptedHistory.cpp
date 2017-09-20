#include "../Public/ReadEncryptedHistory.h"


//begin namespace block
namespace MESSAGES
{

ReadEncryptedHistory::ReadEncryptedHistory()
{
	this->_ConstructorID = 174672767;
	this->_ContentRelated = true;
}

ReadEncryptedHistory::ReadEncryptedHistory(COMMON::InputEncryptedChat* peer, FDateTime max_date)
{
	this->_ConstructorID = 174672767;
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
}
ReadEncryptedHistory::~ReadEncryptedHistory()
{

}
}//end namespace block