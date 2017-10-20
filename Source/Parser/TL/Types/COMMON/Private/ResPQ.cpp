#include "../Public/ResPQ.h"


//begin namespace block
namespace COMMON
{

ResPQ::ResPQ()
{
	this->_ConstructorID = 85337187;
}

ResPQ::ResPQ(TBigInt<128> nonce, TBigInt<128> server_nonce, FString pq, TArray<unsigned long long>  server_public_key_fingerprints)
{
	this->_ConstructorID = 85337187;
	this->nonce = nonce;
	this->server_nonce = server_nonce;
	this->pq = pq;
	this->server_public_key_fingerprints = server_public_key_fingerprints;
}
void ResPQ::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.Write128Int(this->nonce);
	Writer.Write128Int(this->server_nonce);
	Writer.TGWriteString(this->pq);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->server_public_key_fingerprints.Num());
	for(auto X : this->server_public_key_fingerprints)
	{
	Writer.WriteLong(X);
	}
}


void ResPQ::OnResponce(BinaryReader& Reader)
{
	nonce = Reader.Read128Int();
	server_nonce = Reader.Read128Int();
	pq = Reader.TGReadString();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len10393 = Reader.ReadInt();
	for(int32 i = 0; i < Len10393; i++)
	{
	auto X = Reader.ReadLong();
	server_public_key_fingerprints.Add(X);
	}
	this->_Responded = true;
}
ResPQ::~ResPQ()
{
}
}//end namespace block
