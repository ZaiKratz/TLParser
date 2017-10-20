#include "../Public/SavedGifs.h"


//begin namespace block
namespace MESSAGES
{

SavedGifs::SavedGifs()
{
	this->_ConstructorID = 772213157;
}

SavedGifs::SavedGifs(int32 hash, TArray<COMMON::Document*>  gifs)
{
	this->_ConstructorID = 772213157;
	this->hash = hash;
	this->gifs = gifs;
}
void SavedGifs::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->hash);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->gifs.Num());
	for(auto X : this->gifs)
	{
	X->OnSend(Writer);
	}
}


void SavedGifs::OnResponce(BinaryReader& Reader)
{
	hash = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len10025 = Reader.ReadInt();
	for(int32 i = 0; i < Len10025; i++)
	{
	auto X = reinterpret_cast<COMMON::Document*>(Reader.TGReadObject());
	gifs.Add(X);
	}
	this->_Responded = true;
}
SavedGifs::~SavedGifs()
{
}
}//end namespace block
