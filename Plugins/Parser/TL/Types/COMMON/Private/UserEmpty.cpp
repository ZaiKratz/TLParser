#include "../Public/UserEmpty.h"


//begin namespace block
namespace COMMON
{

UserEmpty::UserEmpty()
{
	this->_ConstructorID = -1169161696;
}

UserEmpty::UserEmpty(int32 id)
{
	this->_ConstructorID = -1169161696;
	this->id = id;
}
void UserEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->id);
}


void UserEmpty::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadInt();
}
UserEmpty::~UserEmpty()
{

}
}//end namespace block
