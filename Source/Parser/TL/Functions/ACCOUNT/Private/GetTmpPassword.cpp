#include "../Public/GetTmpPassword.h"


//begin namespace block
namespace ACCOUNT
{

GetTmpPassword::GetTmpPassword()
{
	this->_ConstructorID = 1250046590;
	this->_ContentRelated = true;
}

GetTmpPassword::GetTmpPassword(TArray<uint8>  password_hash, int32 period)
{
	this->_ConstructorID = 1250046590;
	this->_ContentRelated = true;
	this->password_hash = password_hash;
	this->period = period;
}
void GetTmpPassword::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteBytes((unsigned char*)this->password_hash.GetData(), this->password_hash.Num());
	Writer.WriteInt(this->period);
}


void GetTmpPassword::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<ACCOUNT::TmpPassword*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetTmpPassword::~GetTmpPassword()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
