#include "../Public/SentEncryptedFile.h"


//begin namespace block
namespace MESSAGES
{

SentEncryptedFile::SentEncryptedFile()
{
	this->_ConstructorID = 855610260;
}

SentEncryptedFile::SentEncryptedFile(FDateTime date, COMMON::EncryptedFile* file)
{
	this->_ConstructorID = 855610260;
	this->date = date;
	this->file = file;
}
void SentEncryptedFile::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteDate(this->date);
	this->file->OnSend(Writer);
}


void SentEncryptedFile::OnResponce(BinaryReader& Reader)
{
	date = Reader.TGReadDate();
	file = reinterpret_cast<COMMON::EncryptedFile*>(Reader.TGReadObject());
}
SentEncryptedFile::~SentEncryptedFile()
{

}
}//end namespace block
