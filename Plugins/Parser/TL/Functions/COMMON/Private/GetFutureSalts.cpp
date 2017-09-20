#include "../Public/GetFutureSalts.h"


//begin namespace block
namespace COMMON
{

GetFutureSalts::GetFutureSalts()
{
	this->_ConstructorID = 79503801;
	this->_ContentRelated = true;
}

GetFutureSalts::GetFutureSalts(int32 num)
{
	this->_ConstructorID = 79503801;
	this->_ContentRelated = true;
	this->num = num;
}
void GetFutureSalts::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->num);
}


void GetFutureSalts::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::FutureSalts*>(Reader.TGReadObject());
}
GetFutureSalts::~GetFutureSalts()
{

}
}//end namespace block
