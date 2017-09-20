#include "../Public/ShippingOption.h"


//begin namespace block
namespace COMMON
{

ShippingOption::ShippingOption()
{
	this->_ConstructorID = -549707338;
}

ShippingOption::ShippingOption(FString id, FString title, TArray<COMMON::LabeledPrice*> prices)
{
	this->_ConstructorID = -549707338;
	this->id = id;
	this->title = title;
	this->prices = prices;
}
void ShippingOption::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->id);
	Writer.TGWriteString(this->title);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->prices.Num());
	for(auto X : this->prices)
	{
	X->OnSend(Writer);
	}
}


void ShippingOption::OnResponce(BinaryReader& Reader)
{
	id = Reader.TGReadString();
	title = Reader.TGReadString();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len17702 = Reader.ReadInt();
	for(int32 i = 0; i < Len17702; i++)
	{
	auto X = reinterpret_cast<COMMON::LabeledPrice*>(Reader.TGReadObject());
	prices.Add(X);
	}
}
ShippingOption::~ShippingOption()
{

}
}//end namespace block
