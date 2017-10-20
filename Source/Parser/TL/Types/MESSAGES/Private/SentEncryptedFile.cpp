#include "../Public/SentEncryptedFile.h"


//begin namespace block
namespace MESSAGES
{

SentEncryptedFile::SentEncryptedFile()
{
	this->_ConstructorID = -1802240206;
}

SentEncryptedFile::SentEncryptedFile(FDateTime date, COMMON::EncryptedFile*  file)
{
	this->_ConstructorID = -1802240206;
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
	file = reinterpret_cast<COMMON::EncryptedFile* >(Reader.TGReadObject());
	this->_Responded = true;
}
SentEncryptedFile::~SentEncryptedFile()
{
	if(this->file)
	{
		delete this->file;
	}
}
}//end namespace block
