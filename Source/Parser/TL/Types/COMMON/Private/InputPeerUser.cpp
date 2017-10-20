#include "../Public/InputPeerUser.h"


//begin namespace block
namespace COMMON
{

InputPeerUser::InputPeerUser()
{
	this->_ConstructorID = 2072935910;
}

InputPeerUser::InputPeerUser(int32 user_id, unsigned long long access_hash)
{
	this->_ConstructorID = 2072935910;
	this->user_id = user_id;
	this->access_hash = access_hash;
}
void InputPeerUser::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->user_id);
	Writer.WriteLong(this->access_hash);
}


void InputPeerUser::OnResponce(BinaryReader& Reader)
{
	user_id = Reader.ReadInt();
	access_hash = Reader.ReadLong();
	this->_Responded = true;
}
InputPeerUser::~InputPeerUser()
{
}
}//end namespace block
