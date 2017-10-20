#include "../Public/ConfirmCall.h"


//begin namespace block
namespace PHONE
{

ConfirmCall::ConfirmCall()
{
	this->_ConstructorID = 788404002;
	this->_ContentRelated = true;
}

ConfirmCall::ConfirmCall(COMMON::InputPhoneCall*  peer, TArray<uint8>  g_a, unsigned long long key_fingerprint, COMMON::PhoneCallProtocol*  protocol)
{
	this->_ConstructorID = 788404002;
	this->_ContentRelated = true;
	this->peer = peer;
	this->g_a = g_a;
	this->key_fingerprint = key_fingerprint;
	this->protocol = protocol;
}
void ConfirmCall::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	Writer.TGWriteBytes((unsigned char*)this->g_a.GetData(), this->g_a.Num());
	Writer.WriteLong(this->key_fingerprint);
	this->protocol->OnSend(Writer);
}


void ConfirmCall::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<PHONE::PhoneCall*>(Reader.TGReadObject());
	this->_Responded = true;
}
ConfirmCall::~ConfirmCall()
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
