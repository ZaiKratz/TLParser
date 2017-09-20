#include "../Public/InputEncryptedFileLocation.h"


//begin namespace block
namespace COMMON
{

InputEncryptedFileLocation::InputEncryptedFileLocation()
{
	this->_ConstructorID = 1432167413;
}

InputEncryptedFileLocation::InputEncryptedFileLocation(unsigned long long id, unsigned long long access_hash)
{
	this->_ConstructorID = 1432167413;
	this->id = id;
	this->access_hash = access_hash;
}
void InputEncryptedFileLocation::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
	Writer.WriteLong(this->access_hash);
}


void InputEncryptedFileLocation::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
	access_hash = Reader.ReadLong();
}
InputEncryptedFileLocation::~InputEncryptedFileLocation()
{

}
}//end namespace block
