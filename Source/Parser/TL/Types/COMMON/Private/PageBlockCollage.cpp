#include "../Public/PageBlockCollage.h"


//begin namespace block
namespace COMMON
{

PageBlockCollage::PageBlockCollage()
{
	this->_ConstructorID = 145955919;
}

PageBlockCollage::PageBlockCollage(TArray<TLBaseObject*>  items, TLBaseObject*  caption)
{
	this->_ConstructorID = 145955919;
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
	int32 Len9999 = Reader.ReadInt();
	for(int32 i = 0; i < Len9999; i++)
	{
	auto X = reinterpret_cast<TLBaseObject*>(Reader.TGReadObject());
	items.Add(X);
	}
	caption = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
PageBlockCollage::~PageBlockCollage()
{
	if(this->caption)
	{
		delete this->caption;
	}
}
}//end namespace block
