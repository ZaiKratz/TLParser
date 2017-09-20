#include "../Public/CdnFile.h"


//begin namespace block
namespace UPLOAD
{

CdnFile::CdnFile()
{
	this->_ConstructorID = 1338679209;
}

CdnFile::CdnFile(TArray<uint8> bytes)
{
	this->_ConstructorID = 1338679209;
	this->bytes = bytes;
}
void CdnFile::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteBytes((unsigned char*)this->bytes.GetData(), this->bytes.Num());
}


void CdnFile::OnResponce(BinaryReader& Reader)
{
	bytes = Reader.TGReadBytes();
}
CdnFile::~CdnFile()
{

}
}//end namespace block
