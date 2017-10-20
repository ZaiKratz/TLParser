#include "../Public/GetPassword.h"


//begin namespace block
namespace ACCOUNT
{

GetPassword::GetPassword()
{
	this->_ConstructorID = 1418342645;
	this->_ContentRelated = true;
}
void GetPassword::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetPassword::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<ACCOUNT::Password*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetPassword::~GetPassword()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
