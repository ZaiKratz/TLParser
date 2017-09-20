#include "../Public/ArchivedStickers.h"


//begin namespace block
namespace MESSAGES
{

ArchivedStickers::ArchivedStickers()
{
	this->_ConstructorID = -928396465;
}

ArchivedStickers::ArchivedStickers(int32 count, TArray<COMMON::StickerSetCovered*> sets)
{
	this->_ConstructorID = -928396465;
	this->count = count;
	this->sets = sets;
}
void ArchivedStickers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->count);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->sets.Num());
	for(auto X : this->sets)
	{
	X->OnSend(Writer);
	}
}


void ArchivedStickers::OnResponce(BinaryReader& Reader)
{
	count = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len372 = Reader.ReadInt();
	for(int32 i = 0; i < Len372; i++)
	{
	auto X = reinterpret_cast<COMMON::StickerSetCovered*>(Reader.TGReadObject());
	sets.Add(X);
	}
}
ArchivedStickers::~ArchivedStickers()
{

}
}//end namespace block
