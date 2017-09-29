#include "../Public/PaymentResult.h"


//begin namespace block
namespace PAYMENTS
{

PaymentResult::PaymentResult()
{
	this->_ConstructorID = 1314881805;
}

PaymentResult::PaymentResult(COMMON::Updates*  updates)
{
	this->_ConstructorID = 1314881805;
	this->updates = updates;
}
void PaymentResult::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->updates->OnSend(Writer);
}


void PaymentResult::OnResponce(BinaryReader& Reader)
{
	updates = reinterpret_cast<COMMON::Updates* >(Reader.TGReadObject());
	this->_Responded = true;
}
PaymentResult::~PaymentResult()
{

}
}//end namespace block
