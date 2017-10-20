#include "../Public/ServerDHParamsFail.h"


//begin namespace block
namespace COMMON
{

ServerDHParamsFail::ServerDHParamsFail()
{
	this->_ConstructorID = 2043348061;
}

ServerDHParamsFail::ServerDHParamsFail(TBigInt<128> nonce, TBigInt<128> server_nonce, TBigInt<128> new_nonce_hash)
{
	this->_ConstructorID = 2043348061;
	this->nonce = nonce;
	this->server_nonce = server_nonce;
	this->new_nonce_hash = new_nonce_hash;
}
void ServerDHParamsFail::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.Write128Int(this->nonce);
	Writer.Write128Int(this->server_nonce);
	Writer.Write128Int(this->new_nonce_hash);
}


void ServerDHParamsFail::OnResponce(BinaryReader& Reader)
{
	nonce = Reader.Read128Int();
	server_nonce = Reader.Read128Int();
	new_nonce_hash = Reader.Read128Int();
	this->_Responded = true;
}
ServerDHParamsFail::~ServerDHParamsFail()
{
}
}//end namespace block
