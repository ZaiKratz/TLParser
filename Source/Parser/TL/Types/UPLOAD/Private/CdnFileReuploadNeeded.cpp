#include "../Public/CdnFileReuploadNeeded.h"


//begin namespace block
namespace UPLOAD
{

CdnFileReuploadNeeded::CdnFileReuploadNeeded()
{
	this->_ConstructorID = -290921362;
}

CdnFileReuploadNeeded::CdnFileReuploadNeeded(TArray<uint8>  request_token)
{
	this->_ConstructorID = -290921362;
	this->request_token = request_token;
}
void CdnFileReuploadNeeded::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteBytes((unsigned char*)this->request_token.GetData(), this->request_token.Num());
}


void CdnFileReuploadNeeded::OnResponce(BinaryReader& Reader)
{
	request_token = Reader.TGReadBytes();
	this->_Responded = true;
}
CdnFileReuploadNeeded::~CdnFileReuploadNeeded()
{
}
}//end namespace block
