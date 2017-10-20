#include "../Public/SetBotUpdatesStatus.h"


//begin namespace block
namespace HELP
{

SetBotUpdatesStatus::SetBotUpdatesStatus()
{
	this->_ConstructorID = -333262899;
	this->_ContentRelated = true;
}

SetBotUpdatesStatus::SetBotUpdatesStatus(int32 pending_updates_count, FString message)
{
	this->_ConstructorID = -333262899;
	this->_ContentRelated = true;
	this->pending_updates_count = pending_updates_count;
	this->message = message;
}
void SetBotUpdatesStatus::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->pending_updates_count);
	Writer.TGWriteString(this->message);
}


void SetBotUpdatesStatus::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
SetBotUpdatesStatus::~SetBotUpdatesStatus()
{
}
}//end namespace block
