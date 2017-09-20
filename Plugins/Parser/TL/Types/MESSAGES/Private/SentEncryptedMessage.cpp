#include "../Public/SentEncryptedMessage.h"


//begin namespace block
namespace MESSAGES
{

SentEncryptedMessage::SentEncryptedMessage()
{
	this->_ConstructorID = 898174806;
}

SentEncryptedMessage::SentEncryptedMessage(FDateTime date)
{
	this->_ConstructorID = 898174806;
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
}
SentEncryptedMessage::~SentEncryptedMessage()
{

}
}//end namespace block
