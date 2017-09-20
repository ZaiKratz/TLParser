#include "../Public/EncryptedFile.h"


//begin namespace block
namespace COMMON
{

EncryptedFile::EncryptedFile()
{
	this->_ConstructorID = 1285124170;
}

EncryptedFile::EncryptedFile(unsigned long long id, unsigned long long access_hash, int32 size, int32 dc_id, int32 key_fingerprint)
{
	this->_ConstructorID = 1285124170;
	this->id = id;
	this->access_hash = access_hash;
	this->size = size;
	this->dc_id = dc_id;
	this->key_fingerprint = key_fingerprint;
}
void EncryptedFile::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
	Writer.WriteLong(this->access_hash);
	Writer.WriteInt(this->size);
	Writer.WriteInt(this->dc_id);
	Writer.WriteInt(this->key_fingerprint);
}


void EncryptedFile::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
	access_hash = Reader.ReadLong();
	size = Reader.ReadInt();
	dc_id = Reader.ReadInt();
	key_fingerprint = Reader.ReadInt();
}
EncryptedFile::~EncryptedFile()
{

}
}//end namespace block
