#include "../Public/PaymentForm.h"


//begin namespace block
namespace PAYMENTS
{

PaymentForm::PaymentForm()
{
	this->_ConstructorID = -1548855745;
}

PaymentForm::PaymentForm(bool can_save_credentials, bool password_missing, int32 bot_id, COMMON::Invoice* invoice, int32 provider_id, FString url, FString native_provider, COMMON::DataJSON* native_params, COMMON::PaymentRequestedInfo* saved_info, PRIVATE::PaymentSavedCredentials* saved_credentials, TArray<COMMON::User*> users)
{
	this->_ConstructorID = -1548855745;
	this->can_save_credentials = can_save_credentials;
	this->password_missing = password_missing;
	this->bot_id = bot_id;
	this->invoice = invoice;
	this->provider_id = provider_id;
	this->url = url;
	this->native_provider = native_provider;
	this->native_params = native_params;
	this->saved_info = saved_info;
	this->saved_credentials = saved_credentials;
	this->users = users;
}
void PaymentForm::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!can_save_credentials)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(!password_missing)
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	if(!native_provider.IsEmpty())
	{
		Flags |= (1 << 4);
	}
	else
	{
		Flags |= 0;
	}
	if(!native_params)
	{
		Flags |= (1 << 4);
	}
	else
	{
		Flags |= 0;
	}
	if(!saved_info)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!saved_credentials)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->bot_id);
	this->invoice->OnSend(Writer);
	Writer.WriteInt(this->provider_id);
	Writer.TGWriteString(this->url);
	Writer.TGWriteString(this->native_provider);
	if(!this->native_params)
	{
	this->native_params->OnSend(Writer);
	}
	if(!this->saved_info)
	{
	this->saved_info->OnSend(Writer);
	}
	if(!this->saved_credentials)
	{
	this->saved_credentials->OnSend(Writer);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->users.Num());
	for(auto X : this->users)
	{
	X->OnSend(Writer);
	}
}


void PaymentForm::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 2)) != 0) 
	{
		can_save_credentials = true;
	}
	if((Flags & (1 << 3)) != 0) 
	{
		password_missing = true;
	}
	bot_id = Reader.ReadInt();
	invoice = reinterpret_cast<COMMON::Invoice*>(Reader.TGReadObject());
	provider_id = Reader.ReadInt();
	url = Reader.TGReadString();
	if((Flags & (1 << 4)) != 0) 
	{
	native_provider = Reader.TGReadString();
	}
	if((Flags & (1 << 4)) != 0) 
	{
	native_params = reinterpret_cast<COMMON::DataJSON*>(Reader.TGReadObject());
	}
	if((Flags & (1 << 0)) != 0) 
	{
	saved_info = reinterpret_cast<COMMON::PaymentRequestedInfo*>(Reader.TGReadObject());
	}
	if((Flags & (1 << 1)) != 0) 
	{
	saved_credentials = reinterpret_cast<PRIVATE::PaymentSavedCredentials*>(Reader.TGReadObject());
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len5712 = Reader.ReadInt();
	for(int32 i = 0; i < Len5712; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
}
PaymentForm::~PaymentForm()
{

}
}//end namespace block
