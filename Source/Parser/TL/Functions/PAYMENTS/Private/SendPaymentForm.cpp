#include "../Public/SendPaymentForm.h"


//begin namespace block
namespace PAYMENTS
{

SendPaymentForm::SendPaymentForm()
{
	this->_ConstructorID = 730364339;
	this->_ContentRelated = true;
}

SendPaymentForm::SendPaymentForm(int32 msg_id, FString requested_info_id, FString shipping_option_id, COMMON::InputPaymentCredentials*  credentials)
{
	this->_ConstructorID = 730364339;
	this->_ContentRelated = true;
	this->msg_id = msg_id;
	this->requested_info_id = requested_info_id;
	this->shipping_option_id = shipping_option_id;
	this->credentials = credentials;
}
void SendPaymentForm::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!requested_info_id.IsEmpty())
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

	Writer.WriteInt(this->msg_id);
	Writer.TGWriteString(this->requested_info_id);
	Writer.TGWriteString(this->shipping_option_id);
	this->credentials->OnSend(Writer);
}


void SendPaymentForm::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<PAYMENTS::PaymentResult*>(Reader.TGReadObject());
	this->_Responded = true;
}
SendPaymentForm::~SendPaymentForm()
{

}
}//end namespace block
