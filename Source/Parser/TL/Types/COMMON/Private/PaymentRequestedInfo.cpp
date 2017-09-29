#include "../Public/PaymentRequestedInfo.h"


//begin namespace block
namespace COMMON
{

PaymentRequestedInfo::PaymentRequestedInfo()
{
	this->_ConstructorID = -1868808300;
}

PaymentRequestedInfo::PaymentRequestedInfo(FString name, FString phone, FString email, COMMON::PostAddress*  shipping_address)
{
	this->_ConstructorID = -1868808300;
	this->name = name;
	this->phone = phone;
	this->email = email;
	this->shipping_address = shipping_address;
}
void PaymentRequestedInfo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!name.IsEmpty())
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!phone.IsEmpty())
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!email.IsEmpty())
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(shipping_address)
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteString(this->name);
	Writer.TGWriteString(this->phone);
	Writer.TGWriteString(this->email);
	if(!this->shipping_address)
	{
	this->shipping_address->OnSend(Writer);
	}
}


void PaymentRequestedInfo::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
	name = Reader.TGReadString();
	}
	if((Flags & (1 << 1)) != 0) 
	{
	phone = Reader.TGReadString();
	}
	if((Flags & (1 << 2)) != 0) 
	{
	email = Reader.TGReadString();
	}
	if((Flags & (1 << 3)) != 0) 
	{
	shipping_address = reinterpret_cast<COMMON::PostAddress* >(Reader.TGReadObject());
	}
	this->_Responded = true;
}
PaymentRequestedInfo::~PaymentRequestedInfo()
{

}
}//end namespace block
