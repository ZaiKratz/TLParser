#include "../Public/BindTempAuthKey.h"


//begin namespace block
namespace AUTH
{

BindTempAuthKey::BindTempAuthKey()
{
	this->_ConstructorID = -841733627;
	this->_ContentRelated = true;
}

BindTempAuthKey::BindTempAuthKey(unsigned long long perm_auth_key_id, unsigned long long nonce, FDateTime expires_at, TArray<uint8>  encrypted_message)
{
	this->_ConstructorID = -841733627;
	this->_ContentRelated = true;
	this->perm_auth_key_id = perm_auth_key_id;
	this->nonce = nonce;
	this->expires_at = expires_at;
	this->encrypted_message = encrypted_message;
}
void BindTempAuthKey::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->perm_auth_key_id);
	Writer.WriteLong(this->nonce);
	Writer.TGWriteDate(this->expires_at);
	Writer.TGWriteBytes((unsigned char*)this->encrypted_message.GetData(), this->encrypted_message.Num());
}


void BindTempAuthKey::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
BindTempAuthKey::~BindTempAuthKey()
{
}
}//end namespace block
