#include "../Public/PQInnerData.h"


//begin namespace block
namespace COMMON
{

PQInnerData::PQInnerData()
{
	this->_ConstructorID = -2083955988;
}

PQInnerData::PQInnerData(FString pq, FString p, FString q, TBigInt<128> nonce, TBigInt<128> server_nonce, TBigInt<256> new_nonce)
{
	this->_ConstructorID = -2083955988;
	this->pq = pq;
	this->p = p;
	this->q = q;
	this->nonce = nonce;
	this->server_nonce = server_nonce;
	this->new_nonce = new_nonce;
}
void PQInnerData::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->pq);
	Writer.TGWriteString(this->p);
	Writer.TGWriteString(this->q);
	Writer.Write128Int(this->nonce);
	Writer.Write128Int(this->server_nonce);
	Writer.Write256Int(this->new_nonce);
}


void PQInnerData::OnResponce(BinaryReader& Reader)
{
	pq = Reader.TGReadString();
	p = Reader.TGReadString();
	q = Reader.TGReadString();
	nonce = Reader.Read128Int();
	server_nonce = Reader.Read128Int();
	new_nonce = Reader.Read256Int();
	this->_Responded = true;
}
PQInnerData::~PQInnerData()
{
}
}//end namespace block
