#include "../Public/HighScore.h"


//begin namespace block
namespace COMMON
{

HighScore::HighScore()
{
	this->_ConstructorID = 1493171408;
}

HighScore::HighScore(int32 pos, int32 user_id, int32 score)
{
	this->_ConstructorID = 1493171408;
	this->pos = pos;
	this->user_id = user_id;
	this->score = score;
}
void HighScore::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->pos);
	Writer.WriteInt(this->user_id);
	Writer.WriteInt(this->score);
}


void HighScore::OnResponce(BinaryReader& Reader)
{
	pos = Reader.ReadInt();
	user_id = Reader.ReadInt();
	score = Reader.ReadInt();
	this->_Responded = true;
}
HighScore::~HighScore()
{
}
}//end namespace block
