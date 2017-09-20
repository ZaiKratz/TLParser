#include "../Public/EncryptedMessage.h"


//begin namespace block
namespace COMMON
{

EncryptedMessage::EncryptedMessage()
{
	this->_ConstructorID = 415308013;
}

EncryptedMessage::EncryptedMessage(unsigned long long random_id, int32 chat_id, FDateTime date, TArray<uint8> bytes, COMMON::EncryptedFile* file)
{
	this->_ConstructorID = 415308013;
	this->random_id = random_id;
	this->chat_id = chat_id;
	this->date = date;
	this->bytes = bytes;
	this->file = file;
}
void EncryptedMessage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->random_id);
	Writer.WriteInt(this->chat_id);
	Writer.TGWriteDate(this->date);
	Writer.TGWriteBytes((unsigned char*)this->bytes.GetData(), this->bytes.Num());
	this->file->OnSend(Writer);
}


void EncryptedMessage::OnResponce(BinaryReader& Reader)
{
	random_id = Reader.ReadLong();
	chat_id = Reader.ReadInt();
	date = Reader.TGReadDate();
	bytes = Reader.TGReadBytes();
	file = reinterpret_cast<COMMON::EncryptedFile*>(Reader.TGReadObject());
}
EncryptedMessage::~EncryptedMessage()
{

}
}//end namespace block
