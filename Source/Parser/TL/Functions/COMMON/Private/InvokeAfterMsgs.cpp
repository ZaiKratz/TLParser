#include "../Public/InvokeAfterMsgs.h"


//begin namespace block
namespace COMMON
{

InvokeAfterMsgs::InvokeAfterMsgs()
{
	this->_ConstructorID = 1036301552;
	this->_ContentRelated = true;
}

InvokeAfterMsgs::InvokeAfterMsgs(TArray<unsigned long long>  msg_ids, TLBaseObject*  query)
{
	this->_ConstructorID = 1036301552;
	this->_ContentRelated = true;
	this->msg_ids = msg_ids;
	this->query = query;
}
void InvokeAfterMsgs::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->msg_ids.Num());
	for(auto X : this->msg_ids)
	{
	Writer.WriteLong(X);
	}
	this->query->OnSend(Writer);
}


void InvokeAfterMsgs::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<TLBaseObject*>(Reader.TGReadObject());
	this->_Responded = true;
}
InvokeAfterMsgs::~InvokeAfterMsgs()
{
	if(this->query)
	{
		delete this->query;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
