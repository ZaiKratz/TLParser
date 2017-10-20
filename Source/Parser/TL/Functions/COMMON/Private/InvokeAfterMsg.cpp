#include "../Public/InvokeAfterMsg.h"


//begin namespace block
namespace COMMON
{

InvokeAfterMsg::InvokeAfterMsg()
{
	this->_ConstructorID = -878758099;
	this->_ContentRelated = true;
}

InvokeAfterMsg::InvokeAfterMsg(unsigned long long msg_id, TLBaseObject*  query)
{
	this->_ConstructorID = -878758099;
	this->_ContentRelated = true;
	this->msg_id = msg_id;
	this->query = query;
}
void InvokeAfterMsg::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->msg_id);
	this->query->OnSend(Writer);
}


void InvokeAfterMsg::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<TLBaseObject*>(Reader.TGReadObject());
	this->_Responded = true;
}
InvokeAfterMsg::~InvokeAfterMsg()
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
