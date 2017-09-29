#include "../Public/GetCdnFile.h"


//begin namespace block
namespace UPLOAD
{

GetCdnFile::GetCdnFile()
{
	this->_ConstructorID = 536919235;
	this->_ContentRelated = true;
}

GetCdnFile::GetCdnFile(TArray<uint8>  file_token, int32 offset, int32 limit)
{
	this->_ConstructorID = 536919235;
	this->_ContentRelated = true;
	this->file_token = file_token;
	this->offset = offset;
	this->limit = limit;
}
void GetCdnFile::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteBytes((unsigned char*)this->file_token.GetData(), this->file_token.Num());
	Writer.WriteInt(this->offset);
	Writer.WriteInt(this->limit);
}


void GetCdnFile::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<UPLOAD::CdnFile*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetCdnFile::~GetCdnFile()
{

}
}//end namespace block
