#include "../Public/MessageActionGameScore.h"


//begin namespace block
namespace COMMON
{

MessageActionGameScore::MessageActionGameScore()
{
	this->_ConstructorID = -1834538890;
}

MessageActionGameScore::MessageActionGameScore(unsigned long long game_id, int32 score)
{
	this->_ConstructorID = -1834538890;
	this->game_id = game_id;
	this->score = score;
}
void MessageActionGameScore::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->game_id);
	Writer.WriteInt(this->score);
}


void MessageActionGameScore::OnResponce(BinaryReader& Reader)
{
	game_id = Reader.ReadLong();
	score = Reader.ReadInt();
	this->_Responded = true;
}
MessageActionGameScore::~MessageActionGameScore()
{

}
}//end namespace block
