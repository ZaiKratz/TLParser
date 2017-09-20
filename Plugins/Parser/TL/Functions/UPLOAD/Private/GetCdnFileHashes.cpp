#include "../Public/GetCdnFileHashes.h"


//begin namespace block
namespace UPLOAD
{

GetCdnFileHashes::GetCdnFileHashes()
{
	this->_ConstructorID = 2076710391;
	this->_ContentRelated = true;
}

GetCdnFileHashes::GetCdnFileHashes(TArray<uint8> file_token, int32 offset)
{
	this->_ConstructorID = 2076710391;
	this->_ContentRelated = true;
	this->file_token = file_token;
	this->offset = offset;
}
void GetCdnFileHashes::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteBytes((unsigned char*)this->file_token.GetData(), this->file_token.Num());
	Writer.WriteInt(this->offset);
}


void GetCdnFileHashes::OnResponce(BinaryReader& Reader)
{
}
GetCdnFileHashes::~GetCdnFileHashes()
{

}
}//end namespace block
