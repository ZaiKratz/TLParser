#include "../Public/ValidatedRequestedInfo.h"


//begin namespace block
namespace PAYMENTS
{

ValidatedRequestedInfo::ValidatedRequestedInfo()
{
	this->_ConstructorID = -2095561263;
}

ValidatedRequestedInfo::ValidatedRequestedInfo(FString id, TArray<COMMON::ShippingOption*> shipping_options)
{
	this->_ConstructorID = -2095561263;
	this->id = id;
	this->shipping_options = shipping_options;
}
void ValidatedRequestedInfo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!id.IsEmpty())
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

	Writer.TGWriteString(this->id);
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


void ValidatedRequestedInfo::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
	id = Reader.TGReadString();
	}
	if((Flags & (1 << 1)) != 0) 
	{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len16929 = Reader.ReadInt();
	for(int32 i = 0; i < Len16929; i++)
	{
	auto X = reinterpret_cast<COMMON::ShippingOption*>(Reader.TGReadObject());
	shipping_options.Add(X);
	}
	}
}
ValidatedRequestedInfo::~ValidatedRequestedInfo()
{

}
}//end namespace block
