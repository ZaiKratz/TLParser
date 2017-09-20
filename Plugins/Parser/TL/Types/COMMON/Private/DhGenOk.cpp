#include "../Public/DhGenOk.h"


//begin namespace block
namespace COMMON
{

DhGenOk::DhGenOk()
{
	this->_ConstructorID = 888654651;
}

DhGenOk::DhGenOk(TBigInt<128> nonce, TBigInt<128> server_nonce, TBigInt<128> new_nonce_hash1)
{
	this->_ConstructorID = 888654651;
	this->nonce = nonce;
	this->server_nonce = server_nonce;
	this->new_nonce_hash1 = new_nonce_hash1;
}
void DhGenOk::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.Write128Int(this->nonce);
	Writer.Write128Int(this->server_nonce);
	Writer.Write128Int(this->new_nonce_hash1);
}


void DhGenOk::OnResponce(BinaryReader& Reader)
{
	nonce = Reader.Read128Int();
	server_nonce = Reader.Read128Int();
	new_nonce_hash1 = Reader.Read128Int();
}
DhGenOk::~DhGenOk()
{

}
}//end namespace block
