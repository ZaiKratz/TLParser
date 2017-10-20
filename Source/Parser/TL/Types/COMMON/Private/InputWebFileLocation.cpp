#include "../Public/InputWebFileLocation.h"


//begin namespace block
namespace COMMON
{

InputWebFileLocation::InputWebFileLocation()
{
	this->_ConstructorID = -1036396922;
}

InputWebFileLocation::InputWebFileLocation(FString url, unsigned long long access_hash)
{
	this->_ConstructorID = -1036396922;
	this->url = url;
	this->access_hash = access_hash;
}
void InputWebFileLocation::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->url);
	Writer.WriteLong(this->access_hash);
}


void InputWebFileLocation::OnResponce(BinaryReader& Reader)
{
	url = Reader.TGReadString();
	access_hash = Reader.ReadLong();
	this->_Responded = true;
}
InputWebFileLocation::~InputWebFileLocation()
{
}
}//end namespace block
