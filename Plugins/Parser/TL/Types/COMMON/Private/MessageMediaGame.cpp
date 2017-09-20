#include "../Public/MessageMediaGame.h"


//begin namespace block
namespace COMMON
{

MessageMediaGame::MessageMediaGame()
{
	this->_ConstructorID = 143700477;
}

MessageMediaGame::MessageMediaGame(COMMON::Game* game)
{
	this->_ConstructorID = 143700477;
	this->game = game;
}
void MessageMediaGame::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->game->OnSend(Writer);
}


void MessageMediaGame::OnResponce(BinaryReader& Reader)
{
	game = reinterpret_cast<COMMON::Game*>(Reader.TGReadObject());
}
MessageMediaGame::~MessageMediaGame()
{

}
}//end namespace block
