#include "../Public/MessageActionPaymentSent.h"


//begin namespace block
namespace COMMON
{

MessageActionPaymentSent::MessageActionPaymentSent()
{
	this->_ConstructorID = -795055808;
}

MessageActionPaymentSent::MessageActionPaymentSent(FString currency, unsigned long long total_amount)
{
	this->_ConstructorID = -795055808;
	this->currency = currency;
	this->total_amount = total_amount;
}
void MessageActionPaymentSent::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->currency);
	Writer.WriteLong(this->total_amount);
}


void MessageActionPaymentSent::OnResponce(BinaryReader& Reader)
{
	currency = Reader.TGReadString();
	total_amount = Reader.ReadLong();
}
MessageActionPaymentSent::~MessageActionPaymentSent()
{

}
}//end namespace block
