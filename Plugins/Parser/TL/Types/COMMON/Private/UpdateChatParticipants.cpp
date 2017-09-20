#include "../Public/UpdateChatParticipants.h"


//begin namespace block
namespace COMMON
{

UpdateChatParticipants::UpdateChatParticipants()
{
	this->_ConstructorID = 64;
}

UpdateChatParticipants::UpdateChatParticipants(COMMON::ChatParticipants* participants)
{
	this->_ConstructorID = 64;
	this->participants = participants;
}
void UpdateChatParticipants::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->participants->OnSend(Writer);
}


void UpdateChatParticipants::OnResponce(BinaryReader& Reader)
{
	participants = reinterpret_cast<COMMON::ChatParticipants*>(Reader.TGReadObject());
}
UpdateChatParticipants::~UpdateChatParticipants()
{

}
}//end namespace block
