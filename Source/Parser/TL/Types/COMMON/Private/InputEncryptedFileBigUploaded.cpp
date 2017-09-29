#include "../Public/InputEncryptedFileBigUploaded.h"


//begin namespace block
namespace COMMON
{

InputEncryptedFileBigUploaded::InputEncryptedFileBigUploaded()
{
	this->_ConstructorID = 767652808;
}

InputEncryptedFileBigUploaded::InputEncryptedFileBigUploaded(unsigned long long id, int32 parts, int32 key_fingerprint)
{
	this->_ConstructorID = 767652808;
	this->id = id;
	this->parts = parts;
	this->key_fingerprint = key_fingerprint;
}
void InputEncryptedFileBigUploaded::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
	Writer.WriteInt(this->parts);
	Writer.WriteInt(this->key_fingerprint);
}


void InputEncryptedFileBigUploaded::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
	parts = Reader.ReadInt();
	key_fingerprint = Reader.ReadInt();
	this->_Responded = true;
}
InputEncryptedFileBigUploaded::~InputEncryptedFileBigUploaded()
{

}
}//end namespace block
