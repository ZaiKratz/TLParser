#include "../Public/UpdateChatParticipants.h"


//begin namespace block
namespace COMMON
{

UpdateChatParticipants::UpdateChatParticipants()
{
	this->_ConstructorID = 125178264;
}

UpdateChatParticipants::UpdateChatParticipants(COMMON::ChatParticipants*  participants)
{
	this->_ConstructorID = 125178264;
	this->participants = participants;
}
void UpdateChatParticipants::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->participants->OnSend(Writer);
}


void UpdateChatParticipants::OnResponce(BinaryReader& Reader)
{
	participants = reinterpret_cast<COMMON::ChatParticipants* >(Reader.TGReadObject());
	this->_Responded = true;
}
UpdateChatParticipants::~UpdateChatParticipants()
{
	if(this->participants)
	{
		delete this->participants;
	}
}
}//end namespace block
