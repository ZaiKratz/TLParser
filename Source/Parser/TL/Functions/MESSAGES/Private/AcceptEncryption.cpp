#include "../Public/AcceptEncryption.h"


//begin namespace block
namespace MESSAGES
{

AcceptEncryption::AcceptEncryption()
{
	this->_ConstructorID = 1035731989;
	this->_ContentRelated = true;
}

AcceptEncryption::AcceptEncryption(COMMON::InputEncryptedChat*  peer, TArray<uint8>  g_b, unsigned long long key_fingerprint)
{
	this->_ConstructorID = 1035731989;
	this->_ContentRelated = true;
	this->peer = peer;
	this->g_b = g_b;
	this->key_fingerprint = key_fingerprint;
}
void AcceptEncryption::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	Writer.TGWriteBytes((unsigned char*)this->g_b.GetData(), this->g_b.Num());
	Writer.WriteLong(this->key_fingerprint);
}


void AcceptEncryption::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::EncryptedChat*>(Reader.TGReadObject());
	this->_Responded = true;
}
AcceptEncryption::~AcceptEncryption()
{

}
}//end namespace block
