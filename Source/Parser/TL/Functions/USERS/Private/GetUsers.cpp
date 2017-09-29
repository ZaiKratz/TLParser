#include "../Public/GetUsers.h"


//begin namespace block
namespace USERS
{

GetUsers::GetUsers()
{
	this->_ConstructorID = 227648840;
	this->_ContentRelated = true;
}

GetUsers::GetUsers(TArray<COMMON::InputUser*>  id)
{
	this->_ConstructorID = 227648840;
	this->_ContentRelated = true;
	this->id = id;
}
void GetUsers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->id.Num());
	for(auto X : this->id)
	{
	X->OnSend(Writer);
	}
}


void GetUsers::OnResponce(BinaryReader& Reader)
{
	this->_Responded = true;
}
GetUsers::~GetUsers()
{

}
}//end namespace block
