#include "../Public/GetFile.h"


//begin namespace block
namespace UPLOAD
{

GetFile::GetFile()
{
	this->_ConstructorID = -475607115;
	this->_ContentRelated = true;
}

GetFile::GetFile(COMMON::InputFileLocation*  location, int32 offset, int32 limit)
{
	this->_ConstructorID = -475607115;
	this->_ContentRelated = true;
	this->location = location;
	this->offset = offset;
	this->limit = limit;
}
void GetFile::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->location->OnSend(Writer);
	Writer.WriteInt(this->offset);
	Writer.WriteInt(this->limit);
}


void GetFile::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<UPLOAD::File*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetFile::~GetFile()
{

}
}//end namespace block
