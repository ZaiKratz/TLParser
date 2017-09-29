#include "../Public/SendEncryptedFile.h"


//begin namespace block
namespace MESSAGES
{

SendEncryptedFile::SendEncryptedFile()
{
	this->_ConstructorID = -1701831834;
	this->_ContentRelated = true;
}

SendEncryptedFile::SendEncryptedFile(COMMON::InputEncryptedChat*  peer, unsigned long long random_id, TArray<uint8>  data, COMMON::InputEncryptedFile*  file)
{
	this->_ConstructorID = -1701831834;
	this->_ContentRelated = true;
	this->peer = peer;
	this->random_id = random_id;
	this->data = data;
	this->file = file;
}
void SendEncryptedFile::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	Writer.WriteLong(this->random_id);
	Writer.TGWriteBytes((unsigned char*)this->data.GetData(), this->data.Num());
	this->file->OnSend(Writer);
}


void SendEncryptedFile::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::SentEncryptedMessage*>(Reader.TGReadObject());
	this->_Responded = true;
}
SendEncryptedFile::~SendEncryptedFile()
{

}
}//end namespace block
