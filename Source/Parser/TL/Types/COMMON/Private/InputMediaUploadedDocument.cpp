#include "../Public/InputMediaUploadedDocument.h"


//begin namespace block
namespace COMMON
{

InputMediaUploadedDocument::InputMediaUploadedDocument()
{
	this->_ConstructorID = -476700163;
}

InputMediaUploadedDocument::InputMediaUploadedDocument(COMMON::InputFile*  file, COMMON::InputFile*  thumb, FString mime_type, TArray<TLBaseObject*>  attributes, FString caption, TArray<COMMON::InputDocument*>  stickers, int32 ttl_seconds)
{
	this->_ConstructorID = -476700163;
	this->file = file;
	this->thumb = thumb;
	this->mime_type = mime_type;
	this->attributes = attributes;
	this->caption = caption;
	this->stickers = stickers;
	this->ttl_seconds = ttl_seconds;
}
void InputMediaUploadedDocument::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(thumb)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(stickers.Num())
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(ttl_seconds)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->file->OnSend(Writer);
	if(this->thumb)
	{
	this->thumb->OnSend(Writer);
	}
	Writer.TGWriteString(this->mime_type);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->attributes.Num());
	for(auto X : this->attributes)
	{
	X->OnSend(Writer);
	}
	Writer.TGWriteString(this->caption);
	if(this->stickers.Num())
	{
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->stickers.Num());
	for(auto X : this->stickers)
	{
	if(X)
	{
	X->OnSend(Writer);
	}
	}
	}
	if(this->ttl_seconds)
	{
	Writer.WriteInt(this->ttl_seconds);
	}
}


void InputMediaUploadedDocument::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	file = reinterpret_cast<COMMON::InputFile* >(Reader.TGReadObject());
	if((Flags & (1 << 2)) != 0) 
	{
	thumb = reinterpret_cast<COMMON::InputFile* >(Reader.TGReadObject());
	}
	mime_type = Reader.TGReadString();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len8982 = Reader.ReadInt();
	for(int32 i = 0; i < Len8982; i++)
	{
	auto X = reinterpret_cast<TLBaseObject*>(Reader.TGReadObject());
	attributes.Add(X);
	}
	caption = Reader.TGReadString();
	if((Flags & (1 << 0)) != 0) 
	{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len5870 = Reader.ReadInt();
	for(int32 i = 0; i < Len5870; i++)
	{
	auto X = reinterpret_cast<COMMON::InputDocument*>(Reader.TGReadObject());
	stickers.Add(X);
	}
	}
	if((Flags & (1 << 1)) != 0) 
	{
	ttl_seconds = Reader.ReadInt();
	}
	this->_Responded = true;
}
InputMediaUploadedDocument::~InputMediaUploadedDocument()
{
	if(this->file)
	{
		delete this->file;
	}
	if(this->thumb)
	{
		delete this->thumb;
	}
}
}//end namespace block
