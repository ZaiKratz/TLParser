#include "../Public/PaymentSavedCredentialsCard.h"


//begin namespace block
namespace COMMON
{

PaymentSavedCredentialsCard::PaymentSavedCredentialsCard()
{
	this->_ConstructorID = -842892769;
}

PaymentSavedCredentialsCard::PaymentSavedCredentialsCard(FString id, FString title)
{
	this->_ConstructorID = -842892769;
	this->id = id;
	this->title = title;
}
void PaymentSavedCredentialsCard::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->id);
	Writer.TGWriteString(this->title);
}


void PaymentSavedCredentialsCard::OnResponce(BinaryReader& Reader)
{
	id = Reader.TGReadString();
	title = Reader.TGReadString();
	this->_Responded = true;
}
PaymentSavedCredentialsCard::~PaymentSavedCredentialsCard()
{
}
}//end namespace block
