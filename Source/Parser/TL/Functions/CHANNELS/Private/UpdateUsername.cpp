#include "../Public/UpdateUsername.h"


//begin namespace block
namespace CHANNELS
{

UpdateUsername::UpdateUsername()
{
	this->_ConstructorID = 890549214;
	this->_ContentRelated = true;
}

UpdateUsername::UpdateUsername(COMMON::InputChannel*  channel, FString username)
{
	this->_ConstructorID = 890549214;
	this->_ContentRelated = true;
	this->channel = channel;
	this->username = username;
}
void UpdateUsername::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
	Writer.TGWriteString(this->username);
}


void UpdateUsername::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
UpdateUsername::~UpdateUsername()
{

}
}//end namespace block
