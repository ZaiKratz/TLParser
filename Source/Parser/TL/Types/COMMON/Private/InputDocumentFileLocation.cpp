#include "../Public/InputDocumentFileLocation.h"


//begin namespace block
namespace COMMON
{

InputDocumentFileLocation::InputDocumentFileLocation()
{
	this->_ConstructorID = 1125058340;
}

InputDocumentFileLocation::InputDocumentFileLocation(unsigned long long id, unsigned long long access_hash, int32 version)
{
	this->_ConstructorID = 1125058340;
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
	this->_Responded = true;
}
InputDocumentFileLocation::~InputDocumentFileLocation()
{
}
}//end namespace block
