#include "../Public/AcceptCall.h"


//begin namespace block
namespace PHONE
{

AcceptCall::AcceptCall()
{
	this->_ConstructorID = 1003664544;
	this->_ContentRelated = true;
}

AcceptCall::AcceptCall(COMMON::InputPhoneCall*  peer, TArray<uint8>  g_b, COMMON::PhoneCallProtocol*  protocol)
{
	this->_ConstructorID = 1003664544;
	this->_ContentRelated = true;
	this->peer = peer;
	this->g_b = g_b;
	this->protocol = protocol;
}
void AcceptCall::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	Writer.TGWriteBytes((unsigned char*)this->g_b.GetData(), this->g_b.Num());
	this->protocol->OnSend(Writer);
}


void AcceptCall::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<PHONE::PhoneCall*>(Reader.TGReadObject());
	this->_Responded = true;
}
AcceptCall::~AcceptCall()
{
	if(this->peer)
	{
		delete this->peer;
	}
	if(this->protocol)
	{
		delete this->protocol;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
