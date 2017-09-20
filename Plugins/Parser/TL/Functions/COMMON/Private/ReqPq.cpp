#include "../Public/ReqPq.h"


//begin namespace block
namespace COMMON
{

ReqPq::ReqPq()
{
	this->_ConstructorID = 2023179872;
	this->_ContentRelated = true;
}

ReqPq::ReqPq(TBigInt<128> nonce)
{
	this->_ConstructorID = 2023179872;
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
}
ReqPq::~ReqPq()
{

}
}//end namespace block
