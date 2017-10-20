#include "../Public/DhGenRetry.h"


//begin namespace block
namespace COMMON
{

DhGenRetry::DhGenRetry()
{
	this->_ConstructorID = 1188831161;
}

DhGenRetry::DhGenRetry(TBigInt<128> nonce, TBigInt<128> server_nonce, TBigInt<128> new_nonce_hash2)
{
	this->_ConstructorID = 1188831161;
	this->nonce = nonce;
	this->server_nonce = server_nonce;
	this->new_nonce_hash2 = new_nonce_hash2;
}
void DhGenRetry::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.Write128Int(this->nonce);
	Writer.Write128Int(this->server_nonce);
	Writer.Write128Int(this->new_nonce_hash2);
}


void DhGenRetry::OnResponce(BinaryReader& Reader)
{
	nonce = Reader.Read128Int();
	server_nonce = Reader.Read128Int();
	new_nonce_hash2 = Reader.Read128Int();
	this->_Responded = true;
}
DhGenRetry::~DhGenRetry()
{
}
}//end namespace block
