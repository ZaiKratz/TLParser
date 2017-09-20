#include "../Public/InputMediaInvoice.h"


//begin namespace block
namespace COMMON
{

InputMediaInvoice::InputMediaInvoice()
{
	this->_ConstructorID = -2060053102;
}

InputMediaInvoice::InputMediaInvoice(FString title, FString description, COMMON::InputWebDocument* photo, COMMON::Invoice* invoice, TArray<uint8> payload, FString provider, FString start_param)
{
	this->_ConstructorID = -2060053102;
	this->title = title;
	this->description = description;
	this->photo = photo;
	this->invoice = invoice;
	this->payload = payload;
	this->provider = provider;
	this->start_param = start_param;
}
void InputMediaInvoice::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!photo)
	{
		Flags |= (1 << 0);
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
	this->invoice->OnSend(Writer);
	Writer.TGWriteBytes((unsigned char*)this->payload.GetData(), this->payload.Num());
	Writer.TGWriteString(this->provider);
	Writer.TGWriteString(this->start_param);
}


void InputMediaInvoice::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	title = Reader.TGReadString();
	description = Reader.TGReadString();
	if((Flags & (1 << 0)) != 0) 
	{
	photo = reinterpret_cast<COMMON::InputWebDocument*>(Reader.TGReadObject());
	}
	invoice = reinterpret_cast<COMMON::Invoice*>(Reader.TGReadObject());
	payload = Reader.TGReadBytes();
	provider = Reader.TGReadString();
	start_param = Reader.TGReadString();
}
InputMediaInvoice::~InputMediaInvoice()
{

}
}//end namespace block
