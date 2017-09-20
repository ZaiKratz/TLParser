#include "../Public/UpdateUserStatus.h"


//begin namespace block
namespace COMMON
{

UpdateUserStatus::UpdateUserStatus()
{
	this->_ConstructorID = 601422619;
}

UpdateUserStatus::UpdateUserStatus(int32 user_id, PRIVATE::UserStatus* status)
{
	this->_ConstructorID = 601422619;
	this->user_id = user_id;
	this->status = status;
}
void UpdateUserStatus::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->user_id);
	this->status->OnSend(Writer);
}


void UpdateUserStatus::OnResponce(BinaryReader& Reader)
{
	user_id = Reader.ReadInt();
	status = reinterpret_cast<PRIVATE::UserStatus*>(Reader.TGReadObject());
}
UpdateUserStatus::~UpdateUserStatus()
{

}
}//end namespace block
