#include "../Public/SendEncrypted.h"


//begin namespace block
namespace MESSAGES
{

SendEncrypted::SendEncrypted()
{
	this->_ConstructorID = -1451792525;
	this->_ContentRelated = true;
}

SendEncrypted::SendEncrypted(COMMON::InputEncryptedChat*  peer, unsigned long long random_id, TArray<uint8>  data)
{
	this->_ConstructorID = -1451792525;
	this->_ContentRelated = true;
	this->peer = peer;
	this->random_id = random_id;
	this->data = data;
}
void SendEncrypted::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	Writer.WriteLong(this->random_id);
	Writer.TGWriteBytes((unsigned char*)this->data.GetData(), this->data.Num());
}


void SendEncrypted::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::SentEncryptedMessage*>(Reader.TGReadObject());
	this->_Responded = true;
}
SendEncrypted::~SendEncrypted()
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
