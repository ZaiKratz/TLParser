#include "../Public/InputEncryptedFileUploaded.h"


//begin namespace block
namespace COMMON
{

InputEncryptedFileUploaded::InputEncryptedFileUploaded()
{
	this->_ConstructorID = 1690108678;
}

InputEncryptedFileUploaded::InputEncryptedFileUploaded(unsigned long long id, int32 parts, FString md5_checksum, int32 key_fingerprint)
{
	this->_ConstructorID = 1690108678;
	this->id = id;
	this->parts = parts;
	this->md5_checksum = md5_checksum;
	this->key_fingerprint = key_fingerprint;
}
void InputEncryptedFileUploaded::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
	Writer.WriteInt(this->parts);
	Writer.TGWriteString(this->md5_checksum);
	Writer.WriteInt(this->key_fingerprint);
}


void InputEncryptedFileUploaded::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
	parts = Reader.ReadInt();
	md5_checksum = Reader.TGReadString();
	key_fingerprint = Reader.ReadInt();
	this->_Responded = true;
}
InputEncryptedFileUploaded::~InputEncryptedFileUploaded()
{

}
}//end namespace block
