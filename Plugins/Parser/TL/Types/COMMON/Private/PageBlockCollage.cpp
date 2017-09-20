#include "../Public/PageBlockCollage.h"


//begin namespace block
namespace COMMON
{

PageBlockCollage::PageBlockCollage()
{
	this->_ConstructorID = 64;
}

PageBlockCollage::PageBlockCollage(TArray<PRIVATE::PageBlock*> items, PRIVATE::RichText* caption)
{
	this->_ConstructorID = 64;
	this->items = items;
	this->caption = caption;
}
void PageBlockCollage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->items.Num());
	for(auto X : this->items)
	{
	X->OnSend(Writer);
	}
	this->caption->OnSend(Writer);
}


void PageBlockCollage::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len21263 = Reader.ReadInt();
	for(int32 i = 0; i < Len21263; i++)
	{
	auto X = reinterpret_cast<PRIVATE::PageBlock*>(Reader.TGReadObject());
	items.Add(X);
	}
	caption = reinterpret_cast<PRIVATE::RichText*>(Reader.TGReadObject());
}
PageBlockCollage::~PageBlockCollage()
{

}
}//end namespace block
