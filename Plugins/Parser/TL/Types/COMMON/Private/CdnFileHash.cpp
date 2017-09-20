#include "../Public/CdnFileHash.h"


//begin namespace block
namespace COMMON
{

CdnFileHash::CdnFileHash()
{
	this->_ConstructorID = -1882984841;
}

CdnFileHash::CdnFileHash(int32 offset, int32 limit, TArray<uint8> hash)
{
	this->_ConstructorID = -1882984841;
	this->offset = offset;
	this->limit = limit;
	this->hash = hash;
}
void CdnFileHash::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->offset);
	Writer.WriteInt(this->limit);
	Writer.TGWriteBytes((unsigned char*)this->hash.GetData(), this->hash.Num());
}


void CdnFileHash::OnResponce(BinaryReader& Reader)
{
	offset = Reader.ReadInt();
	limit = Reader.ReadInt();
	hash = Reader.TGReadBytes();
}
CdnFileHash::~CdnFileHash()
{

}
}//end namespace block
