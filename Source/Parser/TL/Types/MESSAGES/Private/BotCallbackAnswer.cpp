#include "../Public/BotCallbackAnswer.h"


//begin namespace block
namespace MESSAGES
{

BotCallbackAnswer::BotCallbackAnswer()
{
	this->_ConstructorID = 911761060;
}

BotCallbackAnswer::BotCallbackAnswer(bool alert, bool has_url, FString message, FString url, int32 cache_time)
{
	this->_ConstructorID = 911761060;
	this->alert = alert;
	this->has_url = has_url;
	this->message = message;
	this->url = url;
	this->cache_time = cache_time;
}
void BotCallbackAnswer::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(alert)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(has_url)
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	if(!message.IsEmpty())
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!url.IsEmpty())
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteString(this->message);
	Writer.TGWriteString(this->url);
	Writer.WriteInt(this->cache_time);
}


void BotCallbackAnswer::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 1)) != 0) 
	{
		alert = true;
	}
	if((Flags & (1 << 3)) != 0) 
	{
		has_url = true;
	}
	if((Flags & (1 << 0)) != 0) 
	{
	message = Reader.TGReadString();
	}
	if((Flags & (1 << 2)) != 0) 
	{
	url = Reader.TGReadString();
	}
	cache_time = Reader.ReadInt();
	this->_Responded = true;
}
BotCallbackAnswer::~BotCallbackAnswer()
{
}
}//end namespace block
