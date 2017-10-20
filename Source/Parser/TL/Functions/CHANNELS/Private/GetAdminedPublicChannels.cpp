#include "../Public/GetAdminedPublicChannels.h"


//begin namespace block
namespace CHANNELS
{

GetAdminedPublicChannels::GetAdminedPublicChannels()
{
	this->_ConstructorID = -1920105769;
	this->_ContentRelated = true;
}
void GetAdminedPublicChannels::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetAdminedPublicChannels::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::Chats*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetAdminedPublicChannels::~GetAdminedPublicChannels()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
