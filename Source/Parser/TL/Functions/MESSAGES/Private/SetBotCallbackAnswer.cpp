#include "../Public/SetBotCallbackAnswer.h"


//begin namespace block
namespace MESSAGES
{

SetBotCallbackAnswer::SetBotCallbackAnswer()
{
	this->_ConstructorID = -712043766;
	this->_ContentRelated = true;
}

SetBotCallbackAnswer::SetBotCallbackAnswer(bool alert, unsigned long long query_id, FString message, FString url, int32 cache_time)
{
	this->_ConstructorID = -712043766;
	this->_ContentRelated = true;
	this->alert = alert;
	this->query_id = query_id;
	this->message = message;
	this->url = url;
	this->cache_time = cache_time;
}
void SetBotCallbackAnswer::OnSend(BinaryWriter& Writer)
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

	Writer.WriteLong(this->query_id);
	Writer.TGWriteString(this->message);
	Writer.TGWriteString(this->url);
	Writer.WriteInt(this->cache_time);
}


void SetBotCallbackAnswer::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
SetBotCallbackAnswer::~SetBotCallbackAnswer()
{
}
}//end namespace block
