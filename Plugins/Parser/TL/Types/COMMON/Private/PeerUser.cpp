#include "../Public/PeerUser.h"


//begin namespace block
namespace COMMON
{

PeerUser::PeerUser()
{
	this->_ConstructorID = 1841082781;
}

PeerUser::PeerUser(int32 user_id)
{
	this->_ConstructorID = 1841082781;
	this->user_id = user_id;
}
void PeerUser::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->user_id);
}


void PeerUser::OnResponce(BinaryReader& Reader)
{
	user_id = Reader.ReadInt();
}
PeerUser::~PeerUser()
{

}
}//end namespace block
