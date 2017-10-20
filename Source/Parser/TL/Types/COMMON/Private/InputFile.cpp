#include "../Public/InputFile.h"


//begin namespace block
namespace COMMON
{

InputFile::InputFile()
{
	this->_ConstructorID = -181407105;
}

InputFile::InputFile(unsigned long long id, int32 parts, FString name, FString md5_checksum)
{
	this->_ConstructorID = -181407105;
	this->id = id;
	this->parts = parts;
	this->name = name;
	this->md5_checksum = md5_checksum;
}
void InputFile::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
	Writer.WriteInt(this->parts);
	Writer.TGWriteString(this->name);
	Writer.TGWriteString(this->md5_checksum);
}


void InputFile::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
	parts = Reader.ReadInt();
	name = Reader.TGReadString();
	md5_checksum = Reader.TGReadString();
	this->_Responded = true;
}
InputFile::~InputFile()
{
}
}//end namespace block
