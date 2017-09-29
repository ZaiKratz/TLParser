#include "../Public/UpdateUserPhone.h"


//begin namespace block
namespace COMMON
{

UpdateUserPhone::UpdateUserPhone()
{
	this->_ConstructorID = 314130811;
}

UpdateUserPhone::UpdateUserPhone(int32 user_id, FString phone)
{
	this->_ConstructorID = 314130811;
	this->user_id = user_id;
	this->phone = phone;
}
void UpdateUserPhone::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->user_id);
	Writer.TGWriteString(this->phone);
}


void UpdateUserPhone::OnResponce(BinaryReader& Reader)
{
	user_id = Reader.ReadInt();
	phone = Reader.TGReadString();
	this->_Responded = true;
}
UpdateUserPhone::~UpdateUserPhone()
{

}
}//end namespace block