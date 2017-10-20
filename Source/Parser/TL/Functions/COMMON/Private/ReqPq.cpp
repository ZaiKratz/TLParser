#include "../Public/ReqPq.h"


//begin namespace block
namespace COMMON
{

ReqPq::ReqPq()
{
	this->_ConstructorID = 1615239032;
	this->_ContentRelated = true;
}

ReqPq::ReqPq(TBigInt<128> nonce)
{
	this->_ConstructorID = 1615239032;
	this->_ContentRelated = true;
	this->nonce = nonce;
}
void ReqPq::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.Write128Int(this->nonce);
}


void ReqPq::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::ResPQ*>(Reader.TGReadObject());
	this->_Responded = true;
}
ReqPq::~ReqPq()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
