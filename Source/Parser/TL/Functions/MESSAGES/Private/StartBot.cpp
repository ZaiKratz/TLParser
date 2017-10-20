#include "../Public/StartBot.h"


//begin namespace block
namespace MESSAGES
{

StartBot::StartBot()
{
	this->_ConstructorID = -421563528;
	this->_ContentRelated = true;
}

StartBot::StartBot(COMMON::InputUser*  bot, TLBaseObject*  peer, unsigned long long random_id, FString start_param)
{
	this->_ConstructorID = -421563528;
	this->_ContentRelated = true;
	this->bot = bot;
	this->peer = peer;
	this->random_id = random_id;
	this->start_param = start_param;
}
void StartBot::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->bot->OnSend(Writer);
	this->peer->OnSend(Writer);
	Writer.WriteLong(this->random_id);
	Writer.TGWriteString(this->start_param);
}


void StartBot::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
	this->_Responded = true;
}
StartBot::~StartBot()
{
	if(this->bot)
	{
		delete this->bot;
	}
	if(this->peer)
	{
		delete this->peer;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
