#include "../Public/CheckPassword.h"


//begin namespace block
namespace AUTH
{

CheckPassword::CheckPassword()
{
	this->_ConstructorID = 64;
	this->_ContentRelated = true;
}

CheckPassword::CheckPassword(TArray<uint8> password_hash)
{
	this->_ConstructorID = 64;
	this->_ContentRelated = true;
	this->password_hash = password_hash;
}
void CheckPassword::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteBytes((unsigned char*)this->password_hash.GetData(), this->password_hash.Num());
}


void CheckPassword::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<AUTH::Authorization*>(Reader.TGReadObject());
}
CheckPassword::~CheckPassword()
{

}
}//end namespace block
