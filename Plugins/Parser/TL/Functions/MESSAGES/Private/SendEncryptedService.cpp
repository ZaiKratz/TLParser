#include "../Public/SendEncryptedService.h"


//begin namespace block
namespace MESSAGES
{

SendEncryptedService::SendEncryptedService()
{
	this->_ConstructorID = -1539713998;
	this->_ContentRelated = true;
}

SendEncryptedService::SendEncryptedService(COMMON::InputEncryptedChat* peer, unsigned long long random_id, TArray<uint8> data)
{
	this->_ConstructorID = -1539713998;
	this->_ContentRelated = true;
	this->peer = peer;
	this->random_id = random_id;
	this->data = data;
}
void SendEncryptedService::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	Writer.WriteLong(this->random_id);
	Writer.TGWriteBytes((unsigned char*)this->data.GetData(), this->data.Num());
}


void SendEncryptedService::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::SentEncryptedMessage*>(Reader.TGReadObject());
}
SendEncryptedService::~SendEncryptedService()
{

}
}//end namespace block
