#include "../Public/GetFullUser.h"


//begin namespace block
namespace USERS
{

GetFullUser::GetFullUser()
{
	this->_ConstructorID = -1314574134;
	this->_ContentRelated = true;
}

GetFullUser::GetFullUser(COMMON::InputUser* id)
{
	this->_ConstructorID = -1314574134;
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
}
GetFullUser::~GetFullUser()
{

}
}//end namespace block
