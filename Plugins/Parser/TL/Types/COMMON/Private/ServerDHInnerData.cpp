#include "../Public/ServerDHInnerData.h"


//begin namespace block
namespace COMMON
{

ServerDHInnerData::ServerDHInnerData()
{
	this->_ConstructorID = -1173517899;
}

ServerDHInnerData::ServerDHInnerData(TBigInt<128> nonce, TBigInt<128> server_nonce, int32 g, FString dh_prime, FString g_a, int32 server_time)
{
	this->_ConstructorID = -1173517899;
	this->nonce = nonce;
	this->server_nonce = server_nonce;
	this->g = g;
	this->dh_prime = dh_prime;
	this->g_a = g_a;
	this->server_time = server_time;
}
void ServerDHInnerData::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.Write128Int(this->nonce);
	Writer.Write128Int(this->server_nonce);
	Writer.WriteInt(this->g);
	Writer.TGWriteString(this->dh_prime);
	Writer.TGWriteString(this->g_a);
	Writer.WriteInt(this->server_time);
}


void ServerDHInnerData::OnResponce(BinaryReader& Reader)
{
	nonce = Reader.Read128Int();
	server_nonce = Reader.Read128Int();
	g = Reader.ReadInt();
	dh_prime = Reader.TGReadString();
	g_a = Reader.TGReadString();
	server_time = Reader.ReadInt();
}
ServerDHInnerData::~ServerDHInnerData()
{

}
}//end namespace block
