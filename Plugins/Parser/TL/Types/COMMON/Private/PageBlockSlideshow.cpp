#include "../Public/PageBlockSlideshow.h"


//begin namespace block
namespace COMMON
{

PageBlockSlideshow::PageBlockSlideshow()
{
	this->_ConstructorID = 1669925907;
}

PageBlockSlideshow::PageBlockSlideshow(TArray<PRIVATE::PageBlock*> items, PRIVATE::RichText* caption)
{
	this->_ConstructorID = 1669925907;
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
	int32 Len11746 = Reader.ReadInt();
	for(int32 i = 0; i < Len11746; i++)
	{
	auto X = reinterpret_cast<PRIVATE::PageBlock*>(Reader.TGReadObject());
	items.Add(X);
	}
	caption = reinterpret_cast<PRIVATE::RichText*>(Reader.TGReadObject());
}
PageBlockSlideshow::~PageBlockSlideshow()
{

}
}//end namespace block
