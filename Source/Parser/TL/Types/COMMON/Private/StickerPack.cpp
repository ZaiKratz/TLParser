#include "../Public/StickerPack.h"


//begin namespace block
namespace COMMON
{

StickerPack::StickerPack()
{
	this->_ConstructorID = 313694676;
}

StickerPack::StickerPack(FString emoticon, TArray<unsigned long long>  documents)
{
	this->_ConstructorID = 313694676;
	this->emoticon = emoticon;
	this->documents = documents;
}
void StickerPack::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->emoticon);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->documents.Num());
	for(auto X : this->documents)
	{
	Writer.WriteLong(X);
	}
}


void StickerPack::OnResponce(BinaryReader& Reader)
{
	emoticon = Reader.TGReadString();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len22786 = Reader.ReadInt();
	for(int32 i = 0; i < Len22786; i++)
	{
	auto X = Reader.ReadLong();
	documents.Add(X);
	}
	this->_Responded = true;
}
StickerPack::~StickerPack()
{
}
}//end namespace block
