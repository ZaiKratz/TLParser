#include "../Public/SaveDraft.h"


//begin namespace block
namespace MESSAGES
{

SaveDraft::SaveDraft()
{
	this->_ConstructorID = -1137057461;
	this->_ContentRelated = true;
}

SaveDraft::SaveDraft(bool no_webpage, int32 reply_to_msg_id, PRIVATE::InputPeer*  peer, FString message, TArray<PRIVATE::MessageEntity*>  entities)
{
	this->_ConstructorID = -1137057461;
	this->_ContentRelated = true;
	this->no_webpage = no_webpage;
	this->reply_to_msg_id = reply_to_msg_id;
	this->peer = peer;
	this->message = message;
	this->entities = entities;
}
void SaveDraft::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(no_webpage)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(reply_to_msg_id)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(entities.Num())
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	if(!this->reply_to_msg_id)
	{
	Writer.WriteInt(this->reply_to_msg_id);
	}
	this->peer->OnSend(Writer);
	Writer.TGWriteString(this->message);
	if(this->entities.Num())
	{
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->entities.Num());
	for(auto X : this->entities)
	{
	if(!X)
	{
	X->OnSend(Writer);
	}
	}
	}
}


void SaveDraft::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
SaveDraft::~SaveDraft()
{

}
}//end namespace block
