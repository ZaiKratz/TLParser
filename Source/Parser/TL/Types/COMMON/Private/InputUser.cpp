#include "../Public/InputUser.h"


//begin namespace block
namespace COMMON
{

InputUser::InputUser()
{
	this->_ConstructorID = -668391402;
}

InputUser::InputUser(int32 user_id, unsigned long long access_hash)
{
	this->_ConstructorID = -668391402;
	this->user_id = user_id;
	this->access_hash = access_hash;
}
void InputUser::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->user_id);
	Writer.WriteLong(this->access_hash);
}


void InputUser::OnResponce(BinaryReader& Reader)
{
	user_id = Reader.ReadInt();
	access_hash = Reader.ReadLong();
	this->_Responded = true;
}
InputUser::~InputUser()
{

}
}//end namespace block
