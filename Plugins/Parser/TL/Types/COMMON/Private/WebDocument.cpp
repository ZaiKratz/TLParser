#include "../Public/WebDocument.h"


//begin namespace block
namespace COMMON
{

WebDocument::WebDocument()
{
	this->_ConstructorID = -657777978;
}

WebDocument::WebDocument(FString url, unsigned long long access_hash, int32 size, FString mime_type, TArray<PRIVATE::DocumentAttribute*> attributes, int32 dc_id)
{
	this->_ConstructorID = -657777978;
	this->url = url;
	this->access_hash = access_hash;
	this->size = size;
	this->mime_type = mime_type;
	this->attributes = attributes;
	this->dc_id = dc_id;
}
void WebDocument::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->url);
	Writer.WriteLong(this->access_hash);
	Writer.WriteInt(this->size);
	Writer.TGWriteString(this->mime_type);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->attributes.Num());
	for(auto X : this->attributes)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(this->dc_id);
}


void WebDocument::OnResponce(BinaryReader& Reader)
{
	url = Reader.TGReadString();
	access_hash = Reader.ReadLong();
	size = Reader.ReadInt();
	mime_type = Reader.TGReadString();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len21109 = Reader.ReadInt();
	for(int32 i = 0; i < Len21109; i++)
	{
	auto X = reinterpret_cast<PRIVATE::DocumentAttribute*>(Reader.TGReadObject());
	attributes.Add(X);
	}
	dc_id = Reader.ReadInt();
}
WebDocument::~WebDocument()
{

}
}//end namespace block
