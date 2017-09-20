#include "../Public/UpdateBotWebhookJSON.h"


//begin namespace block
namespace COMMON
{

UpdateBotWebhookJSON::UpdateBotWebhookJSON()
{
	this->_ConstructorID = -1010821245;
}

UpdateBotWebhookJSON::UpdateBotWebhookJSON(COMMON::DataJSON* data)
{
	this->_ConstructorID = -1010821245;
	this->data = data;
}
void UpdateBotWebhookJSON::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->data->OnSend(Writer);
}


void UpdateBotWebhookJSON::OnResponce(BinaryReader& Reader)
{
	data = reinterpret_cast<COMMON::DataJSON*>(Reader.TGReadObject());
}
UpdateBotWebhookJSON::~UpdateBotWebhookJSON()
{

}
}//end namespace block
