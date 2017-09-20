#include "../Public/GetPaymentReceipt.h"


//begin namespace block
namespace PAYMENTS
{

GetPaymentReceipt::GetPaymentReceipt()
{
	this->_ConstructorID = -2136370528;
	this->_ContentRelated = true;
}

GetPaymentReceipt::GetPaymentReceipt(int32 msg_id)
{
	this->_ConstructorID = -2136370528;
	this->_ContentRelated = true;
	this->msg_id = msg_id;
}
void GetPaymentReceipt::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->msg_id);
}


void GetPaymentReceipt::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<PAYMENTS::PaymentReceipt*>(Reader.TGReadObject());
}
GetPaymentReceipt::~GetPaymentReceipt()
{

}
}//end namespace block