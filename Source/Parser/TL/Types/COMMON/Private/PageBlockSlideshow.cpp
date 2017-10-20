#include "../Public/PageBlockSlideshow.h"


//begin namespace block
namespace COMMON
{

PageBlockSlideshow::PageBlockSlideshow()
{
	this->_ConstructorID = 319588707;
}

PageBlockSlideshow::PageBlockSlideshow(TArray<TLBaseObject*>  items, TLBaseObject*  caption)
{
	this->_ConstructorID = 319588707;
	this->items = items;
	this->caption = caption;
}
void PageBlockSlideshow::OnSend(BinaryWriter& Writer)
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


void PageBlockSlideshow::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len21482 = Reader.ReadInt();
	for(int32 i = 0; i < Len21482; i++)
	{
	auto X = reinterpret_cast<TLBaseObject*>(Reader.TGReadObject());
	items.Add(X);
	}
	caption = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
PageBlockSlideshow::~PageBlockSlideshow()
{
	if(this->caption)
	{
		delete this->caption;
	}
}
}//end namespace block
