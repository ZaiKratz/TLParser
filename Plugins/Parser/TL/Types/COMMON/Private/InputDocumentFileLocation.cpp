#include "../Public/InputDocumentFileLocation.h"


//begin namespace block
namespace COMMON
{

InputDocumentFileLocation::InputDocumentFileLocation()
{
	this->_ConstructorID = 604442435;
}

InputDocumentFileLocation::InputDocumentFileLocation(unsigned long long id, unsigned long long access_hash, int32 version)
{
	this->_ConstructorID = 604442435;
	this->id = id;
	this->access_hash = access_hash;
	this->version = version;
}
void InputDocumentFileLocation::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
	Writer.WriteLong(this->access_hash);
	Writer.WriteInt(this->version);
}


void InputDocumentFileLocation::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
	access_hash = Reader.ReadLong();
	version = Reader.ReadInt();
}
InputDocumentFileLocation::~InputDocumentFileLocation()
{

}
}//end namespace block
