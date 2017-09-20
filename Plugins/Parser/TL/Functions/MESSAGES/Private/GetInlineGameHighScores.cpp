#include "../Public/GetInlineGameHighScores.h"


//begin namespace block
namespace MESSAGES
{

GetInlineGameHighScores::GetInlineGameHighScores()
{
	this->_ConstructorID = 64;
	this->_ContentRelated = true;
}

GetInlineGameHighScores::GetInlineGameHighScores(COMMON::InputBotInlineMessageID* id, COMMON::InputUser* user_id)
{
	this->_ConstructorID = 64;
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
}
GetInlineGameHighScores::~GetInlineGameHighScores()
{

}
}//end namespace block
