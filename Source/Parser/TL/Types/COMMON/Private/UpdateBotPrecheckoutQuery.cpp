#include "../Public/UpdateBotPrecheckoutQuery.h"


//begin namespace block
namespace COMMON
{

UpdateBotPrecheckoutQuery::UpdateBotPrecheckoutQuery()
{
	this->_ConstructorID = 1563376297;
}

UpdateBotPrecheckoutQuery::UpdateBotPrecheckoutQuery(unsigned long long query_id, int32 user_id, TArray<uint8>  payload, COMMON::PaymentRequestedInfo*  info, FString shipping_option_id, FString currency, unsigned long long total_amount)
{
	this->_ConstructorID = 1563376297;
	this->query_id = query_id;
	this->user_id = user_id;
	this->payload = payload;
	this->info = info;
	this->shipping_option_id = shipping_option_id;
	this->currency = currency;
	this->total_amount = total_amount;
}
void UpdateBotPrecheckoutQuery::OnSend(BinaryWriter& Writer)
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

	Writer.WriteLong(this->query_id);
	Writer.WriteInt(this->user_id);
	Writer.TGWriteBytes((unsigned char*)this->payload.GetData(), this->payload.Num());
	if(!this->info)
	{
	this->info->OnSend(Writer);
	}
	Writer.TGWriteString(this->shipping_option_id);
	Writer.TGWriteString(this->currency);
	Writer.WriteLong(this->total_amount);
}


void UpdateBotPrecheckoutQuery::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	query_id = Reader.ReadLong();
	user_id = Reader.ReadInt();
	payload = Reader.TGReadBytes();
	if((Flags & (1 << 0)) != 0) 
	{
	info = reinterpret_cast<COMMON::PaymentRequestedInfo* >(Reader.TGReadObject());
	}
	if((Flags & (1 << 1)) != 0) 
	{
	shipping_option_id = Reader.TGReadString();
	}
	currency = Reader.TGReadString();
	total_amount = Reader.ReadLong();
	this->_Responded = true;
}
UpdateBotPrecheckoutQuery::~UpdateBotPrecheckoutQuery()
{

}
}//end namespace block
