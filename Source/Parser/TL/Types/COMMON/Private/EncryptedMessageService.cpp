#include "../Public/EncryptedMessageService.h"


//begin namespace block
namespace COMMON
{

EncryptedMessageService::EncryptedMessageService()
{
	this->_ConstructorID = 594758406;
}

EncryptedMessageService::EncryptedMessageService(unsigned long long random_id, int32 chat_id, FDateTime date, TArray<uint8>  bytes)
{
	this->_ConstructorID = 594758406;
	this->random_id = random_id;
	this->chat_id = chat_id;
	this->date = date;
	this->bytes = bytes;
}
void EncryptedMessageService::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->random_id);
	Writer.WriteInt(this->chat_id);
	Writer.TGWriteDate(this->date);
	Writer.TGWriteBytes((unsigned char*)this->bytes.GetData(), this->bytes.Num());
}


void EncryptedMessageService::OnResponce(BinaryReader& Reader)
{
	random_id = Reader.ReadLong();
	chat_id = Reader.ReadInt();
	date = Reader.TGReadDate();
	bytes = Reader.TGReadBytes();
	this->_Responded = true;
}
EncryptedMessageService::~EncryptedMessageService()
{
}
}//end namespace block
