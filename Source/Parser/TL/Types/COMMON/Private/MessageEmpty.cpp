#include "../Public/MessageEmpty.h"


//begin namespace block
namespace COMMON
{

MessageEmpty::MessageEmpty()
{
	this->_ConstructorID = -2082087340;
}

MessageEmpty::MessageEmpty(int32 id)
{
	this->_ConstructorID = -2082087340;
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
	this->_Responded = true;
}
MessageEmpty::~MessageEmpty()
{

}
}//end namespace block
