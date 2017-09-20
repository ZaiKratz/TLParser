#include "../Public/UpdateUserBlocked.h"


//begin namespace block
namespace COMMON
{

UpdateUserBlocked::UpdateUserBlocked()
{
	this->_ConstructorID = 451472512;
}

UpdateUserBlocked::UpdateUserBlocked(int32 user_id, bool blocked)
{
	this->_ConstructorID = 451472512;
	this->user_id = user_id;
	this->blocked = blocked;
}
void UpdateUserBlocked::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->user_id);
	Writer.WriteBool(this->blocked);
}


void UpdateUserBlocked::OnResponce(BinaryReader& Reader)
{
	user_id = Reader.ReadInt();
	blocked = Reader.ReadBool();
}
UpdateUserBlocked::~UpdateUserBlocked()
{

}
}//end namespace block
