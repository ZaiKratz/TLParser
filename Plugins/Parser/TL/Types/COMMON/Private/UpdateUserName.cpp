#include "../Public/UpdateUserName.h"


//begin namespace block
namespace COMMON
{

UpdateUserName::UpdateUserName()
{
	this->_ConstructorID = 1932211111;
}

UpdateUserName::UpdateUserName(int32 user_id, FString first_name, FString last_name, FString username)
{
	this->_ConstructorID = 1932211111;
	this->user_id = user_id;
	this->first_name = first_name;
	this->last_name = last_name;
	this->username = username;
}
void UpdateUserName::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->user_id);
	Writer.TGWriteString(this->first_name);
	Writer.TGWriteString(this->last_name);
	Writer.TGWriteString(this->username);
}


void UpdateUserName::OnResponce(BinaryReader& Reader)
{
	user_id = Reader.ReadInt();
	first_name = Reader.TGReadString();
	last_name = Reader.TGReadString();
	username = Reader.TGReadString();
}
UpdateUserName::~UpdateUserName()
{

}
}//end namespace block
