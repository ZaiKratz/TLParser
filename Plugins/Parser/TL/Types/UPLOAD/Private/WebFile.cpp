#include "../Public/WebFile.h"


//begin namespace block
namespace UPLOAD
{

WebFile::WebFile()
{
	this->_ConstructorID = -1135352031;
}

WebFile::WebFile(int32 size, FString mime_type, PRIVATE::FileType* file_type, int32 mtime, TArray<uint8> bytes)
{
	this->_ConstructorID = -1135352031;
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
	file_type = reinterpret_cast<PRIVATE::FileType*>(Reader.TGReadObject());
	mtime = Reader.ReadInt();
	bytes = Reader.TGReadBytes();
}
WebFile::~WebFile()
{

}
}//end namespace block