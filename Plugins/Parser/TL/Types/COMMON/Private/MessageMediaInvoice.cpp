#include "../Public/MessageMediaInvoice.h"


//begin namespace block
namespace COMMON
{

MessageMediaInvoice::MessageMediaInvoice()
{
	this->_ConstructorID = 1192449412;
}

MessageMediaInvoice::MessageMediaInvoice(bool shipping_address_requested, bool test, FString title, FString description, COMMON::WebDocument* photo, int32 receipt_msg_id, FString currency, unsigned long long total_amount, FString start_param)
{
	this->_ConstructorID = 1192449412;
	this->shipping_address_requested = shipping_address_requested;
	this->test = test;
	this->title = title;
	this->description = description;
	this->photo = photo;
	this->receipt_msg_id = receipt_msg_id;
	this->currency = currency;
	this->total_amount = total_amount;
	this->start_param = start_param;
}
void MessageMediaInvoice::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!shipping_address_requested)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!test)
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	if(!photo)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!receipt_msg_id)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteString(this->title);
	Writer.TGWriteString(this->description);
	if(!this->photo)
	{
	this->photo->OnSend(Writer);
	}
	if(!this->receipt_msg_id)
	{
	Writer.WriteInt(this->receipt_msg_id);
	}
	Writer.TGWriteString(this->currency);
	Writer.WriteLong(this->total_amount);
	Writer.TGWriteString(this->start_param);
}


void MessageMediaInvoice::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 1)) != 0) 
	{
		shipping_address_requested = true;
	}
	if((Flags & (1 << 3)) != 0) 
	{
		test = true;
	}
	title = Reader.TGReadString();
	description = Reader.TGReadString();
	if((Flags & (1 << 0)) != 0) 
	{
	photo = reinterpret_cast<COMMON::WebDocument*>(Reader.TGReadObject());
	}
	if((Flags & (1 << 2)) != 0) 
	{
	receipt_msg_id = Reader.ReadInt();
	}
	currency = Reader.TGReadString();
	total_amount = Reader.ReadLong();
	start_param = Reader.TGReadString();
}
MessageMediaInvoice::~MessageMediaInvoice()
{

}
}//end namespace block
