#include "../Public/InputMediaUploadedPhoto.h"


//begin namespace block
namespace COMMON
{

InputMediaUploadedPhoto::InputMediaUploadedPhoto()
{
	this->_ConstructorID = 792191537;
}

InputMediaUploadedPhoto::InputMediaUploadedPhoto(COMMON::InputFile*  file, FString caption, TArray<COMMON::InputDocument*>  stickers, int32 ttl_seconds)
{
	this->_ConstructorID = 792191537;
	this->file = file;
	this->caption = caption;
	this->stickers = stickers;
	this->ttl_seconds = ttl_seconds;
}
void InputMediaUploadedPhoto::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
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


void InputMediaUploadedPhoto::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	file = reinterpret_cast<COMMON::InputFile* >(Reader.TGReadObject());
	caption = Reader.TGReadString();
	if((Flags & (1 << 0)) != 0) 
	{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len23152 = Reader.ReadInt();
	for(int32 i = 0; i < Len23152; i++)
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
InputMediaUploadedPhoto::~InputMediaUploadedPhoto()
{
	if(this->file)
	{
		delete this->file;
	}
}
}//end namespace block
