#include "../Public/ServerDHParamsOk.h"


//begin namespace block
namespace COMMON
{

ServerDHParamsOk::ServerDHParamsOk()
{
	this->_ConstructorID = -790100132;
}

ServerDHParamsOk::ServerDHParamsOk(TBigInt<128> nonce, TBigInt<128> server_nonce, FString encrypted_answer)
{
	this->_ConstructorID = -790100132;
	this->nonce = nonce;
	this->server_nonce = server_nonce;
	this->encrypted_answer = encrypted_answer;
}
void ServerDHParamsOk::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.Write128Int(this->nonce);
	Writer.Write128Int(this->server_nonce);
	Writer.TGWriteString(this->encrypted_answer);
}


void ServerDHParamsOk::OnResponce(BinaryReader& Reader)
{
	nonce = Reader.Read128Int();
	server_nonce = Reader.Read128Int();
	encrypted_answer = Reader.TGReadString();
	this->_Responded = true;
}
ServerDHParamsOk::~ServerDHParamsOk()
{
}
}//end namespace block
