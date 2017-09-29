#include "../Public/GetAccountTTL.h"


//begin namespace block
namespace ACCOUNT
{

GetAccountTTL::GetAccountTTL()
{
	this->_ConstructorID = 150761757;
	this->_ContentRelated = true;
}
void GetAccountTTL::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetAccountTTL::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::AccountDaysTTL*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetAccountTTL::~GetAccountTTL()
{

}
}//end namespace block
