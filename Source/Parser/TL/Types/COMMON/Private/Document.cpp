#include "../Public/Document.h"


//begin namespace block
namespace COMMON
{

Document::Document()
{
	this->_ConstructorID = -2027738169;
}

Document::Document(unsigned long long id, unsigned long long access_hash, FDateTime date, FString mime_type, int32 size, COMMON::PhotoSize*  thumb, int32 dc_id, int32 version, TArray<TLBaseObject*>  attributes)
{
	this->_ConstructorID = -2027738169;
	this->id = id;
	this->access_hash = access_hash;
	this->date = date;
	this->mime_type = mime_type;
	this->size = size;
	this->thumb = thumb;
	this->dc_id = dc_id;
	this->version = version;
	this->attributes = attributes;
}
void Document::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->id);
	Writer.WriteLong(this->access_hash);
	Writer.TGWriteDate(this->date);
	Writer.TGWriteString(this->mime_type);
	Writer.WriteInt(this->size);
	this->thumb->OnSend(Writer);
	Writer.WriteInt(this->dc_id);
	Writer.WriteInt(this->version);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->attributes.Num());
	for(auto X : this->attributes)
	{
	X->OnSend(Writer);
	}
}


void Document::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadLong();
	access_hash = Reader.ReadLong();
	date = Reader.TGReadDate();
	mime_type = Reader.TGReadString();
	size = Reader.ReadInt();
	thumb = reinterpret_cast<COMMON::PhotoSize* >(Reader.TGReadObject());
	dc_id = Reader.ReadInt();
	version = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len7202 = Reader.ReadInt();
	for(int32 i = 0; i < Len7202; i++)
	{
	auto X = reinterpret_cast<TLBaseObject*>(Reader.TGReadObject());
	attributes.Add(X);
	}
	this->_Responded = true;
}
Document::~Document()
{
	if(this->thumb)
	{
		delete this->thumb;
	}
}
}//end namespace block
