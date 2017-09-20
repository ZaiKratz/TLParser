#include "../Public/PagePart.h"


//begin namespace block
namespace COMMON
{

PagePart::PagePart()
{
	this->_ConstructorID = -1096925298;
}

PagePart::PagePart(TArray<PRIVATE::PageBlock*> blocks, TArray<COMMON::Photo*> photos, TArray<COMMON::Document*> documents)
{
	this->_ConstructorID = -1096925298;
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
	int32 Len31203 = Reader.ReadInt();
	for(int32 i = 0; i < Len31203; i++)
	{
	auto X = reinterpret_cast<PRIVATE::PageBlock*>(Reader.TGReadObject());
	blocks.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len17379 = Reader.ReadInt();
	for(int32 i = 0; i < Len17379; i++)
	{
	auto X = reinterpret_cast<COMMON::Photo*>(Reader.TGReadObject());
	photos.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len20876 = Reader.ReadInt();
	for(int32 i = 0; i < Len20876; i++)
	{
	auto X = reinterpret_cast<COMMON::Document*>(Reader.TGReadObject());
	documents.Add(X);
	}
}
PagePart::~PagePart()
{

}
}//end namespace block
