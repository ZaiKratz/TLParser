#include "../Public/CheckUsername.h"


//begin namespace block
namespace CHANNELS
{

CheckUsername::CheckUsername()
{
	this->_ConstructorID = 283557164;
	this->_ContentRelated = true;
}

CheckUsername::CheckUsername(COMMON::InputChannel*  channel, FString username)
{
	this->_ConstructorID = 283557164;
	this->_ContentRelated = true;
	this->channel = channel;
	this->username = username;
}
void CheckUsername::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
	Writer.TGWriteString(this->username);
}


void CheckUsername::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
CheckUsername::~CheckUsername()
{
	if(this->channel)
	{
		delete this->channel;
	}
}
}//end namespace block
