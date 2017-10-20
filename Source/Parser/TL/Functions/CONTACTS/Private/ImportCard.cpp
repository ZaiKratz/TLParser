#include "../Public/ImportCard.h"


//begin namespace block
namespace CONTACTS
{

ImportCard::ImportCard()
{
	this->_ConstructorID = 1340184318;
	this->_ContentRelated = true;
}

ImportCard::ImportCard(TArray<int32>  export_card)
{
	this->_ConstructorID = 1340184318;
	this->_ContentRelated = true;
	this->export_card = export_card;
}
void ImportCard::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->export_card.Num());
	for(auto X : this->export_card)
	{
	Writer.WriteInt(X);
	}
}


void ImportCard::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	this->_Responded = true;
}
ImportCard::~ImportCard()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
