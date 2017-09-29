#include "../Public/ReqDHParams.h"


//begin namespace block
namespace COMMON
{

ReqDHParams::ReqDHParams()
{
	this->_ConstructorID = -686627650;
	this->_ContentRelated = true;
}

ReqDHParams::ReqDHParams(TBigInt<128> nonce, TBigInt<128> server_nonce, FString p, FString q, unsigned long long public_key_fingerprint, FString encrypted_data)
{
	this->_ConstructorID = -686627650;
	this->_ContentRelated = true;
	this->nonce = nonce;
	this->server_nonce = server_nonce;
	this->p = p;
	this->q = q;
	this->public_key_fingerprint = public_key_fingerprint;
	this->encrypted_data = encrypted_data;
}
void ReqDHParams::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.Write128Int(this->nonce);
	Writer.Write128Int(this->server_nonce);
	Writer.TGWriteString(this->p);
	Writer.TGWriteString(this->q);
	Writer.WriteLong(this->public_key_fingerprint);
	Writer.TGWriteString(this->encrypted_data);
}


void ReqDHParams::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<PRIVATE::ServerDHParams*>(Reader.TGReadObject());
	this->_Responded = true;
}
ReqDHParams::~ReqDHParams()
{

}
}//end namespace block
