#include "../Public/PaymentCharge.h"


//begin namespace block
namespace COMMON
{

PaymentCharge::PaymentCharge()
{
	this->_ConstructorID = 2126643946;
}

PaymentCharge::PaymentCharge(FString id, FString provider_charge_id)
{
	this->_ConstructorID = 2126643946;
	this->id = id;
	this->provider_charge_id = provider_charge_id;
}
void PaymentCharge::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->id);
	Writer.TGWriteString(this->provider_charge_id);
}


void PaymentCharge::OnResponce(BinaryReader& Reader)
{
	id = Reader.TGReadString();
	provider_charge_id = Reader.TGReadString();
}
PaymentCharge::~PaymentCharge()
{

}
}//end namespace block
