#include "../Public/DeleteMessages.h"


//begin namespace block
namespace CHANNELS
{

DeleteMessages::DeleteMessages()
{
	this->_ConstructorID = -2067661490;
	this->_ContentRelated = true;
}

DeleteMessages::DeleteMessages(COMMON::InputChannel*  channel, TArray<int32>  id)
{
	this->_ConstructorID = -2067661490;
	this->_ContentRelated = true;
	this->channel = channel;
	this->id = id;
}
void DeleteMessages::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->id.Num());
	for(auto X : this->id)
	{
	Writer.WriteInt(X);
	}
}


void DeleteMessages::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::AffectedMessages*>(Reader.TGReadObject());
	this->_Responded = true;
}
DeleteMessages::~DeleteMessages()
{
	if(this->channel)
	{
		delete this->channel;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
