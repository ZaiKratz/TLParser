#include "../Public/UpdateNewEncryptedMessage.h"


//begin namespace block
namespace COMMON
{

UpdateNewEncryptedMessage::UpdateNewEncryptedMessage()
{
	this->_ConstructorID = 314359194;
}

UpdateNewEncryptedMessage::UpdateNewEncryptedMessage(COMMON::EncryptedMessage*  message, int32 qts)
{
	this->_ConstructorID = 314359194;
	this->message = message;
	this->qts = qts;
}
void UpdateNewEncryptedMessage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->message->OnSend(Writer);
	Writer.WriteInt(this->qts);
}


void UpdateNewEncryptedMessage::OnResponce(BinaryReader& Reader)
{
	message = reinterpret_cast<COMMON::EncryptedMessage* >(Reader.TGReadObject());
	qts = Reader.ReadInt();
	this->_Responded = true;
}
UpdateNewEncryptedMessage::~UpdateNewEncryptedMessage()
{

}
}//end namespace block