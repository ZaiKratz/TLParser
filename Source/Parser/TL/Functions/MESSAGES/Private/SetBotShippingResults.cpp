#include "../Public/SetBotShippingResults.h"


//begin namespace block
namespace MESSAGES
{

SetBotShippingResults::SetBotShippingResults()
{
	this->_ConstructorID = -436833542;
	this->_ContentRelated = true;
}

SetBotShippingResults::SetBotShippingResults(unsigned long long query_id, FString error, TArray<COMMON::ShippingOption*>  shipping_options)
{
	this->_ConstructorID = -436833542;
	this->_ContentRelated = true;
	this->query_id = query_id;
	this->error = error;
	this->shipping_options = shipping_options;
}
void SetBotShippingResults::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!error.IsEmpty())
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(shipping_options.Num())
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteLong(this->query_id);
	Writer.TGWriteString(this->error);
	if(this->shipping_options.Num())
	{
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->shipping_options.Num());
	for(auto X : this->shipping_options)
	{
	if(!X)
	{
	X->OnSend(Writer);
	}
	}
	}
}


void SetBotShippingResults::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
SetBotShippingResults::~SetBotShippingResults()
{

}
}//end namespace block
