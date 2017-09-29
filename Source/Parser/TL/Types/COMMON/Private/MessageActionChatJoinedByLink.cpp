#include "../Public/MessageActionChatJoinedByLink.h"


//begin namespace block
namespace COMMON
{

MessageActionChatJoinedByLink::MessageActionChatJoinedByLink()
{
	this->_ConstructorID = -123931160;
}

MessageActionChatJoinedByLink::MessageActionChatJoinedByLink(int32 inviter_id)
{
	this->_ConstructorID = -123931160;
	this->inviter_id = inviter_id;
}
void MessageActionChatJoinedByLink::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->inviter_id);
}


void MessageActionChatJoinedByLink::OnResponce(BinaryReader& Reader)
{
	inviter_id = Reader.ReadInt();
	this->_Responded = true;
}
MessageActionChatJoinedByLink::~MessageActionChatJoinedByLink()
{

}
}//end namespace block
