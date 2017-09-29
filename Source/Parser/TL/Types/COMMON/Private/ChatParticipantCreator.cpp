#include "../Public/ChatParticipantCreator.h"


//begin namespace block
namespace COMMON
{

ChatParticipantCreator::ChatParticipantCreator()
{
	this->_ConstructorID = -636267638;
}

ChatParticipantCreator::ChatParticipantCreator(int32 user_id)
{
	this->_ConstructorID = -636267638;
	this->user_id = user_id;
}
void ChatParticipantCreator::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->user_id);
}


void ChatParticipantCreator::OnResponce(BinaryReader& Reader)
{
	user_id = Reader.ReadInt();
	this->_Responded = true;
}
ChatParticipantCreator::~ChatParticipantCreator()
{

}
}//end namespace block
