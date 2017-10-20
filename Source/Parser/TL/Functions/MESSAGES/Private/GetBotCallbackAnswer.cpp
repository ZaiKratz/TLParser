#include "../Public/GetBotCallbackAnswer.h"


//begin namespace block
namespace MESSAGES
{

GetBotCallbackAnswer::GetBotCallbackAnswer()
{
	this->_ConstructorID = -2130010132;
	this->_ContentRelated = true;
}

GetBotCallbackAnswer::GetBotCallbackAnswer(bool game, TLBaseObject*  peer, int32 msg_id, TArray<uint8>  data)
{
	this->_ConstructorID = -2130010132;
	this->_ContentRelated = true;
	this->game = game;
	this->peer = peer;
	this->msg_id = msg_id;
	this->data = data;
}
void GetBotCallbackAnswer::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(game)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(data.Num())
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->peer->OnSend(Writer);
	Writer.WriteInt(this->msg_id);
	if(this->data.Num())
	{
	Writer.TGWriteBytes((unsigned char*)this->data.GetData(), this->data.Num());
	}
}


void GetBotCallbackAnswer::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::BotCallbackAnswer*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetBotCallbackAnswer::~GetBotCallbackAnswer()
{
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
