#include "../Public/DhGenFail.h"


//begin namespace block
namespace COMMON
{

DhGenFail::DhGenFail()
{
	this->_ConstructorID = -1499615742;
}

DhGenFail::DhGenFail(TBigInt<128> nonce, TBigInt<128> server_nonce, TBigInt<128> new_nonce_hash3)
{
	this->_ConstructorID = -1499615742;
	this->nonce = nonce;
	this->server_nonce = server_nonce;
	this->new_nonce_hash3 = new_nonce_hash3;
}
void DhGenFail::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.Write128Int(this->nonce);
	Writer.Write128Int(this->server_nonce);
	Writer.Write128Int(this->new_nonce_hash3);
}


void DhGenFail::OnResponce(BinaryReader& Reader)
{
	nonce = Reader.Read128Int();
	server_nonce = Reader.Read128Int();
	new_nonce_hash3 = Reader.Read128Int();
	this->_Responded = true;
}
DhGenFail::~DhGenFail()
{

}
}//end namespace block
