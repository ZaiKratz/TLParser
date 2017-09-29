#include "../Public/ContactStatus.h"


//begin namespace block
namespace COMMON
{

ContactStatus::ContactStatus()
{
	this->_ConstructorID = -748155807;
}

ContactStatus::ContactStatus(int32 user_id, PRIVATE::UserStatus*  status)
{
	this->_ConstructorID = -748155807;
	this->user_id = user_id;
	this->status = status;
}
void ContactStatus::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->user_id);
	this->status->OnSend(Writer);
}


void ContactStatus::OnResponce(BinaryReader& Reader)
{
	user_id = Reader.ReadInt();
	status = reinterpret_cast<PRIVATE::UserStatus* >(Reader.TGReadObject());
	this->_Responded = true;
}
ContactStatus::~ContactStatus()
{

}
}//end namespace block
