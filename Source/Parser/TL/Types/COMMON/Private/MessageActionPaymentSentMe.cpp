#include "../Public/MessageActionPaymentSentMe.h"


//begin namespace block
namespace COMMON
{

MessageActionPaymentSentMe::MessageActionPaymentSentMe()
{
	this->_ConstructorID = -1892568281;
}

MessageActionPaymentSentMe::MessageActionPaymentSentMe(FString currency, unsigned long long total_amount, TArray<uint8>  payload, COMMON::PaymentRequestedInfo*  info, FString shipping_option_id, COMMON::PaymentCharge*  charge)
{
	this->_ConstructorID = -1892568281;
	this->currency = currency;
	this->total_amount = total_amount;
	this->payload = payload;
	this->info = info;
	this->shipping_option_id = shipping_option_id;
	this->charge = charge;
}
void MessageActionPaymentSentMe::OnSend(BinaryWriter& Writer)
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
	if(!shipping_option_id.IsEmpty())
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteString(this->currency);
	Writer.WriteLong(this->total_amount);
	Writer.TGWriteBytes((unsigned char*)this->payload.GetData(), this->payload.Num());
	if(this->info)
	{
	this->info->OnSend(Writer);
	}
	Writer.TGWriteString(this->shipping_option_id);
	this->charge->OnSend(Writer);
}


void MessageActionPaymentSentMe::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	currency = Reader.TGReadString();
	total_amount = Reader.ReadLong();
	payload = Reader.TGReadBytes();
	if((Flags & (1 << 0)) != 0) 
	{
	info = reinterpret_cast<COMMON::PaymentRequestedInfo* >(Reader.TGReadObject());
	}
	if((Flags & (1 << 1)) != 0) 
	{
	shipping_option_id = Reader.TGReadString();
	}
	charge = reinterpret_cast<COMMON::PaymentCharge* >(Reader.TGReadObject());
	this->_Responded = true;
}
MessageActionPaymentSentMe::~MessageActionPaymentSentMe()
{
	if(this->info)
	{
		delete this->info;
	}
	if(this->charge)
	{
		delete this->charge;
	}
}
}//end namespace block
