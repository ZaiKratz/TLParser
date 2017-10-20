#include "../Public/SentEncryptedMessage.h"


//begin namespace block
namespace MESSAGES
{

SentEncryptedMessage::SentEncryptedMessage()
{
	this->_ConstructorID = 1443858741;
}

SentEncryptedMessage::SentEncryptedMessage(FDateTime date)
{
	this->_ConstructorID = 1443858741;
	this->date = date;
}
void SentEncryptedMessage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteDate(this->date);
}


void SentEncryptedMessage::OnResponce(BinaryReader& Reader)
{
	date = Reader.TGReadDate();
	this->_Responded = true;
}
SentEncryptedMessage::~SentEncryptedMessage()
{
}
}//end namespace block
