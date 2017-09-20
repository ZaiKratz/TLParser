#include "../Public/TmpPassword.h"


//begin namespace block
namespace ACCOUNT
{

TmpPassword::TmpPassword()
{
	this->_ConstructorID = 889021659;
}

TmpPassword::TmpPassword(TArray<uint8> tmp_password, int32 valid_until)
{
	this->_ConstructorID = 889021659;
	this->tmp_password = tmp_password;
	this->valid_until = valid_until;
}
void TmpPassword::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteBytes((unsigned char*)this->tmp_password.GetData(), this->tmp_password.Num());
	Writer.WriteInt(this->valid_until);
}


void TmpPassword::OnResponce(BinaryReader& Reader)
{
	tmp_password = Reader.TGReadBytes();
	valid_until = Reader.ReadInt();
}
TmpPassword::~TmpPassword()
{

}
}//end namespace block
