#include "../Public/GetMessages.h"


//begin namespace block
namespace MESSAGES
{

GetMessages::GetMessages()
{
	this->_ConstructorID = 1109588596;
	this->_ContentRelated = true;
}

GetMessages::GetMessages(TArray<int32>  id)
{
	this->_ConstructorID = 1109588596;
	this->_ContentRelated = true;
	this->id = id;
}
void GetMessages::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->id.Num());
	for(auto X : this->id)
	{
	Writer.WriteInt(X);
	}
}


void GetMessages::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::Messages*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetMessages::~GetMessages()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
