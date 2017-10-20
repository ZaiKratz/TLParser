#include "../Public/ChatParticipants.h"


//begin namespace block
namespace COMMON
{

ChatParticipants::ChatParticipants()
{
	this->_ConstructorID = 1061556205;
}

ChatParticipants::ChatParticipants(int32 chat_id, TArray<COMMON::ChatParticipant*>  participants, int32 version)
{
	this->_ConstructorID = 1061556205;
	this->chat_id = chat_id;
	this->participants = participants;
	this->version = version;
}
void ChatParticipants::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->chat_id);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->participants.Num());
	for(auto X : this->participants)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(this->version);
}


void ChatParticipants::OnResponce(BinaryReader& Reader)
{
	chat_id = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len22443 = Reader.ReadInt();
	for(int32 i = 0; i < Len22443; i++)
	{
	auto X = reinterpret_cast<COMMON::ChatParticipant*>(Reader.TGReadObject());
	participants.Add(X);
	}
	version = Reader.ReadInt();
	this->_Responded = true;
}
ChatParticipants::~ChatParticipants()
{
}
}//end namespace block
