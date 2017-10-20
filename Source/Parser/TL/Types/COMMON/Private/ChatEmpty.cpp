#include "../Public/ChatEmpty.h"


//begin namespace block
namespace COMMON
{

ChatEmpty::ChatEmpty()
{
	this->_ConstructorID = -1683826688;
}

ChatEmpty::ChatEmpty(int32 id)
{
	this->_ConstructorID = -1683826688;
	this->id = id;
}
void ChatEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->id);
}


void ChatEmpty::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadInt();
	this->_Responded = true;
}
ChatEmpty::~ChatEmpty()
{
}
}//end namespace block
