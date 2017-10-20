#include "../Public/RequestEncryption.h"


//begin namespace block
namespace MESSAGES
{

RequestEncryption::RequestEncryption()
{
	this->_ConstructorID = -162681021;
	this->_ContentRelated = true;
}

RequestEncryption::RequestEncryption(COMMON::InputUser*  user_id, int32 random_id, TArray<uint8>  g_a)
{
	this->_ConstructorID = -162681021;
	this->_ContentRelated = true;
	this->user_id = user_id;
	this->random_id = random_id;
	this->g_a = g_a;
}
void RequestEncryption::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->user_id->OnSend(Writer);
	Writer.WriteInt(this->random_id);
	Writer.TGWriteBytes((unsigned char*)this->g_a.GetData(), this->g_a.Num());
}


void RequestEncryption::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::EncryptedChat*>(Reader.TGReadObject());
	this->_Responded = true;
}
RequestEncryption::~RequestEncryption()
{
	if(this->user_id)
	{
		delete this->user_id;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
