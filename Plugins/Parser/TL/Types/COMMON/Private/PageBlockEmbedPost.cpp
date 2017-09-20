#include "../Public/PageBlockEmbedPost.h"


//begin namespace block
namespace COMMON
{

PageBlockEmbedPost::PageBlockEmbedPost()
{
	this->_ConstructorID = -377803735;
}

PageBlockEmbedPost::PageBlockEmbedPost(FString url, unsigned long long webpage_id, unsigned long long author_photo_id, FString author, FDateTime date, TArray<PRIVATE::PageBlock*> blocks, PRIVATE::RichText* caption)
{
	this->_ConstructorID = -377803735;
	this->url = url;
	this->webpage_id = webpage_id;
	this->author_photo_id = author_photo_id;
	this->author = author;
	this->date = date;
	this->blocks = blocks;
	this->caption = caption;
}
void PageBlockEmbedPost::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->url);
	Writer.WriteLong(this->webpage_id);
	Writer.WriteLong(this->author_photo_id);
	Writer.TGWriteString(this->author);
	Writer.TGWriteDate(this->date);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->blocks.Num());
	for(auto X : this->blocks)
	{
	X->OnSend(Writer);
	}
	this->caption->OnSend(Writer);
}


void PageBlockEmbedPost::OnResponce(BinaryReader& Reader)
{
	url = Reader.TGReadString();
	webpage_id = Reader.ReadLong();
	author_photo_id = Reader.ReadLong();
	author = Reader.TGReadString();
	date = Reader.TGReadDate();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len14686 = Reader.ReadInt();
	for(int32 i = 0; i < Len14686; i++)
	{
	auto X = reinterpret_cast<PRIVATE::PageBlock*>(Reader.TGReadObject());
	blocks.Add(X);
	}
	caption = reinterpret_cast<PRIVATE::RichText*>(Reader.TGReadObject());
}
PageBlockEmbedPost::~PageBlockEmbedPost()
{

}
}//end namespace block
