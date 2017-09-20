#include "../Public/GetPassword.h"


//begin namespace block
namespace ACCOUNT
{

GetPassword::GetPassword()
{
	this->_ConstructorID = -181368236;
	this->_ContentRelated = true;
}
void GetPassword::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetPassword::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<ACCOUNT::Password*>(Reader.TGReadObject());
}
GetPassword::~GetPassword()
{

}
}//end namespace block
