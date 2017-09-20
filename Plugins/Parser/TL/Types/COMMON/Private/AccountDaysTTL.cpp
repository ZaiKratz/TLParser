#include "../Public/AccountDaysTTL.h"


//begin namespace block
namespace COMMON
{

AccountDaysTTL::AccountDaysTTL()
{
	this->_ConstructorID = -542125896;
}

AccountDaysTTL::AccountDaysTTL(int32 days)
{
	this->_ConstructorID = -542125896;
	this->days = days;
}
void AccountDaysTTL::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->days);
}


void AccountDaysTTL::OnResponce(BinaryReader& Reader)
{
	days = Reader.ReadInt();
}
AccountDaysTTL::~AccountDaysTTL()
{

}
}//end namespace block
