#include "../Public/PaymentVerficationNeeded.h"


//begin namespace block
namespace PAYMENTS
{

PaymentVerficationNeeded::PaymentVerficationNeeded()
{
	this->_ConstructorID = 565794411;
}

PaymentVerficationNeeded::PaymentVerficationNeeded(FString url)
{
	this->_ConstructorID = 565794411;
	this->url = url;
}
void PaymentVerficationNeeded::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->url);
}


void PaymentVerficationNeeded::OnResponce(BinaryReader& Reader)
{
	url = Reader.TGReadString();
}
PaymentVerficationNeeded::~PaymentVerficationNeeded()
{

}
}//end namespace block
