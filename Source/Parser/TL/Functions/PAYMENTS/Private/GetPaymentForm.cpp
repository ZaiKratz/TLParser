#include "../Public/GetPaymentForm.h"


//begin namespace block
namespace PAYMENTS
{

GetPaymentForm::GetPaymentForm()
{
	this->_ConstructorID = -1712285883;
	this->_ContentRelated = true;
}

GetPaymentForm::GetPaymentForm(int32 msg_id)
{
	this->_ConstructorID = -1712285883;
	this->_ContentRelated = true;
	this->msg_id = msg_id;
}
void GetPaymentForm::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->msg_id);
}


void GetPaymentForm::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<PAYMENTS::PaymentForm*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetPaymentForm::~GetPaymentForm()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
