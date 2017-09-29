#include "../Public/RequestCall.h"


//begin namespace block
namespace PHONE
{

RequestCall::RequestCall()
{
	this->_ConstructorID = 1536537556;
	this->_ContentRelated = true;
}

RequestCall::RequestCall(COMMON::InputUser*  user_id, int32 random_id, TArray<uint8>  g_a_hash, COMMON::PhoneCallProtocol*  protocol)
{
	this->_ConstructorID = 1536537556;
	this->_ContentRelated = true;
	this->user_id = user_id;
	this->random_id = random_id;
	this->g_a_hash = g_a_hash;
	this->protocol = protocol;
}
void RequestCall::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->user_id->OnSend(Writer);
	Writer.WriteInt(this->random_id);
	Writer.TGWriteBytes((unsigned char*)this->g_a_hash.GetData(), this->g_a_hash.Num());
	this->protocol->OnSend(Writer);
}


void RequestCall::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<PHONE::PhoneCall*>(Reader.TGReadObject());
	this->_Responded = true;
}
RequestCall::~RequestCall()
{

}
}//end namespace block
