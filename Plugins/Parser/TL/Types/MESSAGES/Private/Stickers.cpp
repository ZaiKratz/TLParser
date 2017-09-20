#include "../Public/Stickers.h"


//begin namespace block
namespace MESSAGES
{

Stickers::Stickers()
{
	this->_ConstructorID = 852332170;
}

Stickers::Stickers(FString hash, TArray<COMMON::Document*> stickers)
{
	this->_ConstructorID = 852332170;
	this->hash = hash;
	this->stickers = stickers;
}
void Stickers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->hash);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->stickers.Num());
	for(auto X : this->stickers)
	{
	X->OnSend(Writer);
	}
}


void Stickers::OnResponce(BinaryReader& Reader)
{
	hash = Reader.TGReadString();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len27163 = Reader.ReadInt();
	for(int32 i = 0; i < Len27163; i++)
	{
	auto X = reinterpret_cast<COMMON::Document*>(Reader.TGReadObject());
	stickers.Add(X);
	}
}
Stickers::~Stickers()
{

}
}//end namespace block
