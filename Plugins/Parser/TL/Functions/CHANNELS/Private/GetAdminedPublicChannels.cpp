#include "../Public/GetAdminedPublicChannels.h"


//begin namespace block
namespace CHANNELS
{

GetAdminedPublicChannels::GetAdminedPublicChannels()
{
	this->_ConstructorID = -679309939;
	this->_ContentRelated = true;
}
void GetAdminedPublicChannels::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetAdminedPublicChannels::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::Chats*>(Reader.TGReadObject());
}
GetAdminedPublicChannels::~GetAdminedPublicChannels()
{

}
}//end namespace block
