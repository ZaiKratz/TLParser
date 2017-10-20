#include "../Public/GetInlineGameHighScores.h"


//begin namespace block
namespace MESSAGES
{

GetInlineGameHighScores::GetInlineGameHighScores()
{
	this->_ConstructorID = 258170395;
	this->_ContentRelated = true;
}

GetInlineGameHighScores::GetInlineGameHighScores(COMMON::InputBotInlineMessageID*  id, COMMON::InputUser*  user_id)
{
	this->_ConstructorID = 258170395;
	this->_ContentRelated = true;
	this->id = id;
	this->user_id = user_id;
}
void GetInlineGameHighScores::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->id->OnSend(Writer);
	this->user_id->OnSend(Writer);
}


void GetInlineGameHighScores::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::HighScores*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetInlineGameHighScores::~GetInlineGameHighScores()
{
	if(this->id)
	{
		delete this->id;
	}
	if(this->user_id)
	{
		delete this->user_id;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
