#include "../Public/DeleteUserHistory.h"


//begin namespace block
namespace CHANNELS
{

DeleteUserHistory::DeleteUserHistory()
{
	this->_ConstructorID = 467078609;
	this->_ContentRelated = true;
}

DeleteUserHistory::DeleteUserHistory(COMMON::InputChannel* channel, COMMON::InputUser* user_id)
{
	this->_ConstructorID = 467078609;
	this->_ContentRelated = true;
	this->channel = channel;
	this->user_id = user_id;
}
void DeleteUserHistory::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
	this->user_id->OnSend(Writer);
}


void DeleteUserHistory::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::AffectedHistory*>(Reader.TGReadObject());
}
DeleteUserHistory::~DeleteUserHistory()
{

}
}//end namespace block
