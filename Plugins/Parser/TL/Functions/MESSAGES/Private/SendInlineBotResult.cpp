#include "../Public/SendInlineBotResult.h"


//begin namespace block
namespace MESSAGES
{

SendInlineBotResult::SendInlineBotResult()
{
	this->_ConstructorID = -33132879;
	this->_ContentRelated = true;
}

SendInlineBotResult::SendInlineBotResult(bool silent, bool background, bool clear_draft, PRIVATE::InputPeer* peer, int32 reply_to_msg_id, unsigned long long random_id, unsigned long long query_id, FString id)
{
	this->_ConstructorID = -33132879;
	this->_ContentRelated = true;
	this->silent = silent;
	this->background = background;
	this->clear_draft = clear_draft;
	this->peer = peer;
	this->reply_to_msg_id = reply_to_msg_id;
	this->random_id = random_id;
	this->query_id = query_id;
	this->id = id;
}
void SendInlineBotResult::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!silent)
	{
		Flags |= (1 << 5);
	}
	else
	{
		Flags |= 0;
	}
	if(!background)
	{
		Flags |= (1 << 6);
	}
	else
	{
		Flags |= 0;
	}
	if(!clear_draft)
	{
		Flags |= (1 << 7);
	}
	else
	{
		Flags |= 0;
	}
	if(!reply_to_msg_id)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->peer->OnSend(Writer);
	if(!this->reply_to_msg_id)
	{
	Writer.WriteInt(this->reply_to_msg_id);
	}
	Writer.WriteLong(this->random_id);
	Writer.WriteLong(this->query_id);
	Writer.TGWriteString(this->id);
}


void SendInlineBotResult::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
}
SendInlineBotResult::~SendInlineBotResult()
{

}
}//end namespace block
