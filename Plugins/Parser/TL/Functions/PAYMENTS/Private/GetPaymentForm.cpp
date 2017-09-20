#include "../Public/GetPaymentForm.h"


//begin namespace block
namespace PAYMENTS
{

GetPaymentForm::GetPaymentForm()
{
	this->_ConstructorID = 1167585433;
	this->_ContentRelated = true;
}

GetPaymentForm::GetPaymentForm(int32 msg_id)
{
	this->_ConstructorID = 1167585433;
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
}
GetPaymentForm::~GetPaymentForm()
{

}
}//end namespace block
