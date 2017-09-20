#include "../Public/PageFull.h"


//begin namespace block
namespace COMMON
{

PageFull::PageFull()
{
	this->_ConstructorID = -1429770667;
}

PageFull::PageFull(TArray<PRIVATE::PageBlock*> blocks, TArray<COMMON::Photo*> photos, TArray<COMMON::Document*> documents)
{
	this->_ConstructorID = -1429770667;
	this->blocks = blocks;
	this->photos = photos;
	this->documents = documents;
}
void PageFull::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->blocks.Num());
	for(auto X : this->blocks)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->photos.Num());
	for(auto X : this->photos)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->documents.Num());
	for(auto X : this->documents)
	{
	X->OnSend(Writer);
	}
}


void PageFull::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len17536 = Reader.ReadInt();
	for(int32 i = 0; i < Len17536; i++)
	{
	auto X = reinterpret_cast<PRIVATE::PageBlock*>(Reader.TGReadObject());
	blocks.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len15113 = Reader.ReadInt();
	for(int32 i = 0; i < Len15113; i++)
	{
	auto X = reinterpret_cast<COMMON::Photo*>(Reader.TGReadObject());
	photos.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len16310 = Reader.ReadInt();
	for(int32 i = 0; i < Len16310; i++)
	{
	auto X = reinterpret_cast<COMMON::Document*>(Reader.TGReadObject());
	documents.Add(X);
	}
}
PageFull::~PageFull()
{

}
}//end namespace block
