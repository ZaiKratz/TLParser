#include "../Public/GetGameHighScores.h"


//begin namespace block
namespace MESSAGES
{

GetGameHighScores::GetGameHighScores()
{
	this->_ConstructorID = -400399203;
	this->_ContentRelated = true;
}

GetGameHighScores::GetGameHighScores(PRIVATE::InputPeer*  peer, int32 id, COMMON::InputUser*  user_id)
{
	this->_ConstructorID = -400399203;
	this->_ContentRelated = true;
	this->peer = peer;
	this->id = id;
	this->user_id = user_id;
}
void GetGameHighScores::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	Writer.WriteInt(this->id);
	this->user_id->OnSend(Writer);
}


void GetGameHighScores::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::HighScores*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetGameHighScores::~GetGameHighScores()
{

}
}//end namespace block
