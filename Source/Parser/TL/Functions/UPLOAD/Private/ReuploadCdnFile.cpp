#include "../Public/ReuploadCdnFile.h"


//begin namespace block
namespace UPLOAD
{

ReuploadCdnFile::ReuploadCdnFile()
{
	this->_ConstructorID = 452533257;
	this->_ContentRelated = true;
}

ReuploadCdnFile::ReuploadCdnFile(TArray<uint8>  file_token, TArray<uint8>  request_token)
{
	this->_ConstructorID = 452533257;
	this->_ContentRelated = true;
	this->file_token = file_token;
	this->request_token = request_token;
}
void ReuploadCdnFile::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteBytes((unsigned char*)this->file_token.GetData(), this->file_token.Num());
	Writer.TGWriteBytes((unsigned char*)this->request_token.GetData(), this->request_token.Num());
}


void ReuploadCdnFile::OnResponce(BinaryReader& Reader)
{
	this->_Responded = true;
}
ReuploadCdnFile::~ReuploadCdnFile()
{
}
}//end namespace block
