#include "../Public/PageBlockList.h"


//begin namespace block
namespace COMMON
{

PageBlockList::PageBlockList()
{
	this->_ConstructorID = -188262342;
}

PageBlockList::PageBlockList(bool ordered, TArray<PRIVATE::RichText*> items)
{
	this->_ConstructorID = -188262342;
	this->ordered = ordered;
	this->items = items;
}
void PageBlockList::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteBool(this->ordered);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->items.Num());
	for(auto X : this->items)
	{
	X->OnSend(Writer);
	}
}


void PageBlockList::OnResponce(BinaryReader& Reader)
{
	ordered = Reader.ReadBool();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len13350 = Reader.ReadInt();
	for(int32 i = 0; i < Len13350; i++)
	{
	auto X = reinterpret_cast<PRIVATE::RichText*>(Reader.TGReadObject());
	items.Add(X);
	}
}
PageBlockList::~PageBlockList()
{

}
}//end namespace block