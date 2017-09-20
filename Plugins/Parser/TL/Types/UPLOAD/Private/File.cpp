#include "../Public/File.h"


//begin namespace block
namespace UPLOAD
{

File::File()
{
	this->_ConstructorID = 64;
}

File::File(PRIVATE::FileType* type, int32 mtime, TArray<uint8> bytes)
{
	this->_ConstructorID = 64;
	this->type = type;
	this->mtime = mtime;
	this->bytes = bytes;
}
void File::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->type->OnSend(Writer);
	Writer.WriteInt(this->mtime);
	Writer.TGWriteBytes((unsigned char*)this->bytes.GetData(), this->bytes.Num());
}


void File::OnResponce(BinaryReader& Reader)
{
	type = reinterpret_cast<PRIVATE::FileType*>(Reader.TGReadObject());
	mtime = Reader.ReadInt();
	bytes = Reader.TGReadBytes();
}
File::~File()
{

}
}//end namespace block
