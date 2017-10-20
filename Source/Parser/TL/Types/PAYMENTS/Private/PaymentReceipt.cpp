#include "../Public/PaymentReceipt.h"


//begin namespace block
namespace PAYMENTS
{

PaymentReceipt::PaymentReceipt()
{
	this->_ConstructorID = 1342771681;
}

PaymentReceipt::PaymentReceipt(FDateTime date, int32 bot_id, COMMON::Invoice*  invoice, int32 provider_id, COMMON::PaymentRequestedInfo*  info, COMMON::ShippingOption*  shipping, FString currency, unsigned long long total_amount, FString credentials_title, TArray<COMMON::User*>  users)
{
	this->_ConstructorID = 1342771681;
	this->date = date;
	this->bot_id = bot_id;
	this->invoice = invoice;
	this->provider_id = provider_id;
	this->info = info;
	this->shipping = shipping;
	this->currency = currency;
	this->total_amount = total_amount;
	this->credentials_title = credentials_title;
	this->users = users;
}
void PaymentReceipt::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(info)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(shipping)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteDate(this->date);
	Writer.WriteInt(this->bot_id);
	this->invoice->OnSend(Writer);
	Writer.WriteInt(this->provider_id);
	if(this->info)
	{
	this->info->OnSend(Writer);
	}
	if(this->shipping)
	{
	this->shipping->OnSend(Writer);
	}
	Writer.TGWriteString(this->currency);
	Writer.WriteLong(this->total_amount);
	Writer.TGWriteString(this->credentials_title);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->users.Num());
	for(auto X : this->users)
	{
	X->OnSend(Writer);
	}
}


void PaymentReceipt::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	date = Reader.TGReadDate();
	bot_id = Reader.ReadInt();
	invoice = reinterpret_cast<COMMON::Invoice* >(Reader.TGReadObject());
	provider_id = Reader.ReadInt();
	if((Flags & (1 << 0)) != 0) 
	{
	info = reinterpret_cast<COMMON::PaymentRequestedInfo* >(Reader.TGReadObject());
	}
	if((Flags & (1 << 1)) != 0) 
	{
	shipping = reinterpret_cast<COMMON::ShippingOption* >(Reader.TGReadObject());
	}
	currency = Reader.TGReadString();
	total_amount = Reader.ReadLong();
	credentials_title = Reader.TGReadString();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len30833 = Reader.ReadInt();
	for(int32 i = 0; i < Len30833; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
	this->_Responded = true;
}
PaymentReceipt::~PaymentReceipt()
{
	if(this->invoice)
	{
		delete this->invoice;
	}
	if(this->info)
	{
		delete this->info;
	}
	if(this->shipping)
	{
		delete this->shipping;
	}
}
}//end namespace block
