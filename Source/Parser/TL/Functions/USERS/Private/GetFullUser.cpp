#include "../Public/GetFullUser.h"


//begin namespace block
namespace USERS
{

GetFullUser::GetFullUser()
{
	this->_ConstructorID = -902781519;
	this->_ContentRelated = true;
}

GetFullUser::GetFullUser(COMMON::InputUser*  id)
{
	this->_ConstructorID = -902781519;
	this->_ContentRelated = true;
	this->id = id;
}
void GetFullUser::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->id->OnSend(Writer);
}


void GetFullUser::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::UserFull*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetFullUser::~GetFullUser()
{
	if(this->id)
	{
		delete this->id;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
