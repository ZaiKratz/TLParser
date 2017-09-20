#include "../Public/ClientDHInnerData.h"


//begin namespace block
namespace COMMON
{

ClientDHInnerData::ClientDHInnerData()
{
	this->_ConstructorID = 1421230950;
}

ClientDHInnerData::ClientDHInnerData(TBigInt<128> nonce, TBigInt<128> server_nonce, unsigned long long retry_id, FString g_b)
{
	this->_ConstructorID = 1421230950;
	this->nonce = nonce;
	this->server_nonce = server_nonce;
	this->retry_id = retry_id;
	this->g_b = g_b;
}
void ClientDHInnerData::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.Write128Int(this->nonce);
	Writer.Write128Int(this->server_nonce);
	Writer.WriteLong(this->retry_id);
	Writer.TGWriteString(this->g_b);
}


void ClientDHInnerData::OnResponce(BinaryReader& Reader)
{
	nonce = Reader.Read128Int();
	server_nonce = Reader.Read128Int();
	retry_id = Reader.ReadLong();
	g_b = Reader.TGReadString();
}
ClientDHInnerData::~ClientDHInnerData()
{

}
}//end namespace block
