#include "../Public/SetGameScore.h"


//begin namespace block
namespace MESSAGES
{

SetGameScore::SetGameScore()
{
	this->_ConstructorID = -1058211698;
	this->_ContentRelated = true;
}

SetGameScore::SetGameScore(bool edit_message, bool force, PRIVATE::InputPeer* peer, int32 id, COMMON::InputUser* user_id, int32 score)
{
	this->_ConstructorID = -1058211698;
	this->_ContentRelated = true;
	this->edit_message = edit_message;
	this->force = force;
	this->peer = peer;
	this->id = id;
	this->user_id = user_id;
	this->score = score;
}
void SetGameScore::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!edit_message)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!force)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->peer->OnSend(Writer);
	Writer.WriteInt(this->id);
	this->user_id->OnSend(Writer);
	Writer.WriteInt(this->score);
}


void SetGameScore::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
}
SetGameScore::~SetGameScore()
{

}
}//end namespace block
