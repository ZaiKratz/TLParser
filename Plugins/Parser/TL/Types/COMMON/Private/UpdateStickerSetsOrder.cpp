#include "../Public/UpdateStickerSetsOrder.h"


//begin namespace block
namespace COMMON
{

UpdateStickerSetsOrder::UpdateStickerSetsOrder()
{
	this->_ConstructorID = 64;
}

UpdateStickerSetsOrder::UpdateStickerSetsOrder(bool masks, TArray<unsigned long long> order)
{
	this->_ConstructorID = 64;
	this->masks = masks;
	this->order = order;
}
void UpdateStickerSetsOrder::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!masks)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->order.Num());
	for(auto X : this->order)
	{
	Writer.WriteLong(X);
	}
}


void UpdateStickerSetsOrder::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		masks = true;
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len26713 = Reader.ReadInt();
	for(int32 i = 0; i < Len26713; i++)
	{
	auto X = Reader.ReadLong();
	order.Add(X);
	}
}
UpdateStickerSetsOrder::~UpdateStickerSetsOrder()
{

}
}//end namespace block
