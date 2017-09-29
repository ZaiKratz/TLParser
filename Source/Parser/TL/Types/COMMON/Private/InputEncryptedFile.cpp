#include "../Public/InputEncryptedFile.h"


//begin namespace block
namespace COMMON
{

InputEncryptedFile::InputEncryptedFile()
{
	this->_ConstructorID = 1511503333;
}

InputEncryptedFile::InputEncryptedFile(unsigned long long id, unsigned long long access_hash)
{
	this->_ConstructorID = 1511503333;
	this->id = id;
	this->access_hash = access_hash;
}
void InputEncryptedFile::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
	Writer.WriteLong(this->access_hash);
}


void InputEncryptedFile::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
	access_hash = Reader.ReadLong();
	this->_Responded = true;
}
InputEncryptedFile::~InputEncryptedFile()
{

}
}//end namespace block
