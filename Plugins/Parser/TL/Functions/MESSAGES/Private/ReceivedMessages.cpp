#include "../Public/ReceivedMessages.h"


//begin namespace block
namespace MESSAGES
{

ReceivedMessages::ReceivedMessages()
{
	this->_ConstructorID = 18;
	this->_ContentRelated = true;
}

ReceivedMessages::ReceivedMessages(int32 max_id)
{
	this->_ConstructorID = 18;
	this->_ContentRelated = true;
	this->max_id = max_id;
}
void ReceivedMessages::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->max_id);
}


void ReceivedMessages::OnResponce(BinaryReader& Reader)
{
}
ReceivedMessages::~ReceivedMessages()
{

}
}//end namespace block
