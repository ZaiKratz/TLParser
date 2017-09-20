#include "../Public/MessageEmpty.h"


//begin namespace block
namespace COMMON
{

MessageEmpty::MessageEmpty()
{
	this->_ConstructorID = 1423893891;
}

MessageEmpty::MessageEmpty(int32 id)
{
	this->_ConstructorID = 1423893891;
	this->id = id;
}
void MessageEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->id);
}


void MessageEmpty::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadInt();
}
MessageEmpty::~MessageEmpty()
{

}
}//end namespace block
