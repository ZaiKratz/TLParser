#include "../Public/GetWebFile.h"


//begin namespace block
namespace UPLOAD
{

GetWebFile::GetWebFile()
{
	this->_ConstructorID = -1920866780;
	this->_ContentRelated = true;
}

GetWebFile::GetWebFile(COMMON::InputWebFileLocation* location, int32 offset, int32 limit)
{
	this->_ConstructorID = -1920866780;
	this->_ContentRelated = true;
	this->location = location;
	this->offset = offset;
	this->limit = limit;
}
void GetWebFile::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->location->OnSend(Writer);
	Writer.WriteInt(this->offset);
	Writer.WriteInt(this->limit);
}


void GetWebFile::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<UPLOAD::WebFile*>(Reader.TGReadObject());
}
GetWebFile::~GetWebFile()
{

}
}//end namespace block
