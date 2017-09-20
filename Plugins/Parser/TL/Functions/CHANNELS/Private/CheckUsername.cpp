#include "../Public/CheckUsername.h"


//begin namespace block
namespace CHANNELS
{

CheckUsername::CheckUsername()
{
	this->_ConstructorID = 750642704;
	this->_ContentRelated = true;
}

CheckUsername::CheckUsername(COMMON::InputChannel* channel, FString username)
{
	this->_ConstructorID = 750642704;
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
}
CheckUsername::~CheckUsername()
{

}
}//end namespace block
