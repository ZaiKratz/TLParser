#include "../Public/PagePart.h"


//begin namespace block
namespace COMMON
{

PagePart::PagePart()
{
	this->_ConstructorID = -1908433218;
}

PagePart::PagePart(TArray<TLBaseObject*>  blocks, TArray<COMMON::Photo*>  photos, TArray<COMMON::Document*>  documents)
{
	this->_ConstructorID = -1908433218;
	this->blocks = blocks;
	this->photos = photos;
	this->documents = documents;
}
void PagePart::OnSend(BinaryWriter& Writer)
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


void PagePart::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len10133 = Reader.ReadInt();
	for(int32 i = 0; i < Len10133; i++)
	{
	auto X = reinterpret_cast<TLBaseObject*>(Reader.TGReadObject());
	blocks.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len18901 = Reader.ReadInt();
	for(int32 i = 0; i < Len18901; i++)
	{
	auto X = reinterpret_cast<COMMON::Photo*>(Reader.TGReadObject());
	photos.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len18304 = Reader.ReadInt();
	for(int32 i = 0; i < Len18304; i++)
	{
	auto X = reinterpret_cast<COMMON::Document*>(Reader.TGReadObject());
	documents.Add(X);
	}
	this->_Responded = true;
}
PagePart::~PagePart()
{
}
}//end namespace block
