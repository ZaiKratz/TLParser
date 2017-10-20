#include "../Public/WebFile.h"


//begin namespace block
namespace UPLOAD
{

WebFile::WebFile()
{
	this->_ConstructorID = 568808380;
}

WebFile::WebFile(int32 size, FString mime_type, TLBaseObject*  file_type, int32 mtime, TArray<uint8>  bytes)
{
	this->_ConstructorID = 568808380;
	this->size = size;
	this->mime_type = mime_type;
	this->file_type = file_type;
	this->mtime = mtime;
	this->bytes = bytes;
}
void WebFile::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->size);
	Writer.TGWriteString(this->mime_type);
	this->file_type->OnSend(Writer);
	Writer.WriteInt(this->mtime);
	Writer.TGWriteBytes((unsigned char*)this->bytes.GetData(), this->bytes.Num());
}


void WebFile::OnResponce(BinaryReader& Reader)
{
	size = Reader.ReadInt();
	mime_type = Reader.TGReadString();
	file_type = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	mtime = Reader.ReadInt();
	bytes = Reader.TGReadBytes();
	this->_Responded = true;
}
WebFile::~WebFile()
{
	if(this->file_type)
	{
		delete this->file_type;
	}
}
}//end namespace block
