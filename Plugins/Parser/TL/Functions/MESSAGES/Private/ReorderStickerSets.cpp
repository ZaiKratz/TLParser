#include "../Public/ReorderStickerSets.h"


//begin namespace block
namespace MESSAGES
{

ReorderStickerSets::ReorderStickerSets()
{
	this->_ConstructorID = 964113272;
	this->_ContentRelated = true;
}

ReorderStickerSets::ReorderStickerSets(bool masks, TArray<unsigned long long> order)
{
	this->_ConstructorID = 964113272;
	this->_ContentRelated = true;
	this->masks = masks;
	this->order = order;
}
void ReorderStickerSets::OnSend(BinaryWriter& Writer)
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


void ReorderStickerSets::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
}
ReorderStickerSets::~ReorderStickerSets()
{

}
}//end namespace block
