#include "../Public/UpdateBotWebhookJSON.h"


//begin namespace block
namespace COMMON
{

UpdateBotWebhookJSON::UpdateBotWebhookJSON()
{
	this->_ConstructorID = -2095595325;
}

UpdateBotWebhookJSON::UpdateBotWebhookJSON(COMMON::DataJSON*  data)
{
	this->_ConstructorID = -2095595325;
	this->data = data;
}
void UpdateBotWebhookJSON::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->data->OnSend(Writer);
}


void UpdateBotWebhookJSON::OnResponce(BinaryReader& Reader)
{
	data = reinterpret_cast<COMMON::DataJSON* >(Reader.TGReadObject());
	this->_Responded = true;
}
UpdateBotWebhookJSON::~UpdateBotWebhookJSON()
{

}
}//end namespace block
