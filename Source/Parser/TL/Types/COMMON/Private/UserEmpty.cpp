#include "../Public/UserEmpty.h"


//begin namespace block
namespace COMMON
{

UserEmpty::UserEmpty()
{
	this->_ConstructorID = 537022650;
}

UserEmpty::UserEmpty(int32 id)
{
	this->_ConstructorID = 537022650;
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
	this->_Responded = true;
}
UserEmpty::~UserEmpty()
{

}
}//end namespace block
