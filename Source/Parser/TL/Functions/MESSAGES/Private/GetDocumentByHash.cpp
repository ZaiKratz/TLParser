#include "../Public/GetDocumentByHash.h"


//begin namespace block
namespace MESSAGES
{

GetDocumentByHash::GetDocumentByHash()
{
	this->_ConstructorID = 864953444;
	this->_ContentRelated = true;
}

GetDocumentByHash::GetDocumentByHash(TArray<uint8>  sha256, int32 size, FString mime_type)
{
	this->_ConstructorID = 864953444;
	this->_ContentRelated = true;
	this->sha256 = sha256;
	this->size = size;
	this->mime_type = mime_type;
}
void GetDocumentByHash::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteBytes((unsigned char*)this->sha256.GetData(), this->sha256.Num());
	Writer.WriteInt(this->size);
	Writer.TGWriteString(this->mime_type);
}


void GetDocumentByHash::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Document*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetDocumentByHash::~GetDocumentByHash()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
