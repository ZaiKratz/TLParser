#include "../Public/Invoice.h"


//begin namespace block
namespace COMMON
{

Invoice::Invoice()
{
	this->_ConstructorID = 1487080131;
}

Invoice::Invoice(bool test, bool name_requested, bool phone_requested, bool email_requested, bool shipping_address_requested, bool flexible, FString currency, TArray<COMMON::LabeledPrice*> prices)
{
	this->_ConstructorID = 1487080131;
	this->test = test;
	this->name_requested = name_requested;
	this->phone_requested = phone_requested;
	this->email_requested = email_requested;
	this->shipping_address_requested = shipping_address_requested;
	this->flexible = flexible;
	this->currency = currency;
	this->prices = prices;
}
void Invoice::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!test)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!name_requested)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!phone_requested)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(!email_requested)
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	if(!shipping_address_requested)
	{
		Flags |= (1 << 4);
	}
	else
	{
		Flags |= 0;
	}
	if(!flexible)
	{
		Flags |= (1 << 5);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteString(this->currency);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->prices.Num());
	for(auto X : this->prices)
	{
	X->OnSend(Writer);
	}
}


void Invoice::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		test = true;
	}
	if((Flags & (1 << 1)) != 0) 
	{
		name_requested = true;
	}
	if((Flags & (1 << 2)) != 0) 
	{
		phone_requested = true;
	}
	if((Flags & (1 << 3)) != 0) 
	{
		email_requested = true;
	}
	if((Flags & (1 << 4)) != 0) 
	{
		shipping_address_requested = true;
	}
	if((Flags & (1 << 5)) != 0) 
	{
		flexible = true;
	}
	currency = Reader.TGReadString();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len13704 = Reader.ReadInt();
	for(int32 i = 0; i < Len13704; i++)
	{
	auto X = reinterpret_cast<COMMON::LabeledPrice*>(Reader.TGReadObject());
	prices.Add(X);
	}
}
Invoice::~Invoice()
{

}
}//end namespace block
