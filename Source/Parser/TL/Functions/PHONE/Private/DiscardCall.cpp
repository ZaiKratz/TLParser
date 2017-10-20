#include "../Public/DiscardCall.h"


//begin namespace block
namespace PHONE
{

DiscardCall::DiscardCall()
{
	this->_ConstructorID = 2027164582;
	this->_ContentRelated = true;
}

DiscardCall::DiscardCall(COMMON::InputPhoneCall*  peer, int32 duration, TLBaseObject*  reason, unsigned long long connection_id)
{
	this->_ConstructorID = 2027164582;
	this->_ContentRelated = true;
	this->peer = peer;
	this->duration = duration;
	this->reason = reason;
	this->connection_id = connection_id;
}
void DiscardCall::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	Writer.WriteInt(this->duration);
	this->reason->OnSend(Writer);
	Writer.WriteLong(this->connection_id);
}


void DiscardCall::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
	this->_Responded = true;
}
DiscardCall::~DiscardCall()
{
	if(this->peer)
	{
		delete this->peer;
	}
	if(this->reason)
	{
		delete this->reason;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
