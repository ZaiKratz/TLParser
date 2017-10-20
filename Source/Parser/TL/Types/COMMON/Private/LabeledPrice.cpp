#include "../Public/LabeledPrice.h"


//begin namespace block
namespace COMMON
{

LabeledPrice::LabeledPrice()
{
	this->_ConstructorID = -886477832;
}

LabeledPrice::LabeledPrice(FString label, unsigned long long amount)
{
	this->_ConstructorID = -886477832;
	this->label = label;
	this->amount = amount;
}
void LabeledPrice::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->label);
	Writer.WriteLong(this->amount);
}


void LabeledPrice::OnResponce(BinaryReader& Reader)
{
	label = Reader.TGReadString();
	amount = Reader.ReadLong();
	this->_Responded = true;
}
LabeledPrice::~LabeledPrice()
{
}
}//end namespace block
