#include "../Public/ContactBlocked.h"


//begin namespace block
namespace COMMON
{

ContactBlocked::ContactBlocked()
{
	this->_ConstructorID = 2043157334;
}

ContactBlocked::ContactBlocked(int32 user_id, FDateTime date)
{
	this->_ConstructorID = 2043157334;
	this->user_id = user_id;
	this->date = date;
}
void ContactBlocked::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->user_id);
	Writer.TGWriteDate(this->date);
}


void ContactBlocked::OnResponce(BinaryReader& Reader)
{
	user_id = Reader.ReadInt();
	date = Reader.TGReadDate();
}
ContactBlocked::~ContactBlocked()
{

}
}//end namespace block
