#include "../Public/PhotoSize.h"


//begin namespace block
namespace COMMON
{

PhotoSize::PhotoSize()
{
	this->_ConstructorID = 2009052699;
}

PhotoSize::PhotoSize(FString type, COMMON::FileLocation*  location, int32 w, int32 h, int32 size)
{
	this->_ConstructorID = 2009052699;
	this->type = type;
	this->location = location;
	this->w = w;
	this->h = h;
	this->size = size;
}
void PhotoSize::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->type);
	this->location->OnSend(Writer);
	Writer.WriteInt(this->w);
	Writer.WriteInt(this->h);
	Writer.WriteInt(this->size);
}


void PhotoSize::OnResponce(BinaryReader& Reader)
{
	type = Reader.TGReadString();
	location = reinterpret_cast<COMMON::FileLocation* >(Reader.TGReadObject());
	w = Reader.ReadInt();
	h = Reader.ReadInt();
	size = Reader.ReadInt();
	this->_Responded = true;
}
PhotoSize::~PhotoSize()
{

}
}//end namespace block
