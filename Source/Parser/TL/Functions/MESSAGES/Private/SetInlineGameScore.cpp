#include "../Public/SetInlineGameScore.h"


//begin namespace block
namespace MESSAGES
{

SetInlineGameScore::SetInlineGameScore()
{
	this->_ConstructorID = 363700068;
	this->_ContentRelated = true;
}

SetInlineGameScore::SetInlineGameScore(bool edit_message, bool force, COMMON::InputBotInlineMessageID*  id, COMMON::InputUser*  user_id, int32 score)
{
	this->_ConstructorID = 363700068;
	this->_ContentRelated = true;
	this->edit_message = edit_message;
	this->force = force;
	this->id = id;
	this->user_id = user_id;
	this->score = score;
}
void SetInlineGameScore::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(edit_message)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(force)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->id->OnSend(Writer);
	this->user_id->OnSend(Writer);
	Writer.WriteInt(this->score);
}


void SetInlineGameScore::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
SetInlineGameScore::~SetInlineGameScore()
{
	if(this->id)
	{
		delete this->id;
	}
	if(this->user_id)
	{
		delete this->user_id;
	}
}
}//end namespace block
