#include "../Public/UpdateBotWebhookJSONQuery.h"


//begin namespace block
namespace COMMON
{

UpdateBotWebhookJSONQuery::UpdateBotWebhookJSONQuery()
{
	this->_ConstructorID = -1505717605;
}

UpdateBotWebhookJSONQuery::UpdateBotWebhookJSONQuery(unsigned long long query_id, COMMON::DataJSON* data, int32 timeout)
{
	this->_ConstructorID = -1505717605;
	this->query_id = query_id;
	this->data = data;
	this->timeout = timeout;
}
void UpdateBotWebhookJSONQuery::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->query_id);
	this->data->OnSend(Writer);
	Writer.WriteInt(this->timeout);
}


void UpdateBotWebhookJSONQuery::OnResponce(BinaryReader& Reader)
{
	query_id = Reader.ReadLong();
	data = reinterpret_cast<COMMON::DataJSON*>(Reader.TGReadObject());
	timeout = Reader.ReadInt();
}
UpdateBotWebhookJSONQuery::~UpdateBotWebhookJSONQuery()
{

}
}//end namespace block
