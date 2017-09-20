#include "../Public/PhotoCachedSize.h"


//begin namespace block
namespace COMMON
{

PhotoCachedSize::PhotoCachedSize()
{
	this->_ConstructorID = -97212439;
}

PhotoCachedSize::PhotoCachedSize(FString type, COMMON::FileLocation* location, int32 w, int32 h, TArray<uint8> bytes)
{
	this->_ConstructorID = -97212439;
	this->type = type;
	this->location = location;
	this->w = w;
	this->h = h;
	this->bytes = bytes;
}
void PhotoCachedSize::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->type);
	this->location->OnSend(Writer);
	Writer.WriteInt(this->w);
	Writer.WriteInt(this->h);
	Writer.TGWriteBytes((unsigned char*)this->bytes.GetData(), this->bytes.Num());
}


void PhotoCachedSize::OnResponce(BinaryReader& Reader)
{
	type = Reader.TGReadString();
	location = reinterpret_cast<COMMON::FileLocation*>(Reader.TGReadObject());
	w = Reader.ReadInt();
	h = Reader.ReadInt();
	bytes = Reader.TGReadBytes();
}
PhotoCachedSize::~PhotoCachedSize()
{

}
}//end namespace block
