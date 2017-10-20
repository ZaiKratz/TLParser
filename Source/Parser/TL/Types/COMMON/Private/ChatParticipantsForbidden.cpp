#include "../Public/ChatParticipantsForbidden.h"


//begin namespace block
namespace COMMON
{

ChatParticipantsForbidden::ChatParticipantsForbidden()
{
	this->_ConstructorID = -57668565;
}

ChatParticipantsForbidden::ChatParticipantsForbidden(int32 chat_id, COMMON::ChatParticipant*  self_participant)
{
	this->_ConstructorID = -57668565;
	this->chat_id = chat_id;
	this->self_participant = self_participant;
}
void ChatParticipantsForbidden::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(self_participant)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->chat_id);
	if(this->self_participant)
	{
	this->self_participant->OnSend(Writer);
	}
}


void ChatParticipantsForbidden::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	chat_id = Reader.ReadInt();
	if((Flags & (1 << 0)) != 0) 
	{
	self_participant = reinterpret_cast<COMMON::ChatParticipant* >(Reader.TGReadObject());
	}
	this->_Responded = true;
}
ChatParticipantsForbidden::~ChatParticipantsForbidden()
{
	if(this->self_participant)
	{
		delete this->self_participant;
	}
}
}//end namespace block
