#include "../Public/UpdateUsername.h"


//begin namespace block
namespace ACCOUNT
{

UpdateUsername::UpdateUsername()
{
	this->_ConstructorID = 2094861118;
	this->_ContentRelated = true;
}

UpdateUsername::UpdateUsername(FString username)
{
	this->_ConstructorID = 2094861118;
	this->_ContentRelated = true;
	this->username = username;
}
void UpdateUsername::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->username);
}


void UpdateUsername::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
}
UpdateUsername::~UpdateUsername()
{

}
}//end namespace block
