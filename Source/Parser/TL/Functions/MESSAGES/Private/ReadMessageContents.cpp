#include "../Public/ReadMessageContents.h"


//begin namespace block
namespace MESSAGES
{

ReadMessageContents::ReadMessageContents()
{
	this->_ConstructorID = 916930423;
	this->_ContentRelated = true;
}

ReadMessageContents::ReadMessageContents(TArray<int32>  id)
{
	this->_ConstructorID = 916930423;
	this->_ContentRelated = true;
	this->id = id;
}
void ReadMessageContents::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->id.Num());
	for(auto X : this->id)
	{
	Writer.WriteInt(X);
	}
}


void ReadMessageContents::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::AffectedMessages*>(Reader.TGReadObject());
	this->_Responded = true;
}
ReadMessageContents::~ReadMessageContents()
{

}
}//end namespace block
