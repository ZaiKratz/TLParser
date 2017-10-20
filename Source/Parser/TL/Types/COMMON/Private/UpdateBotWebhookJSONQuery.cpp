#include "../Public/UpdateBotWebhookJSONQuery.h"


//begin namespace block
namespace COMMON
{

UpdateBotWebhookJSONQuery::UpdateBotWebhookJSONQuery()
{
	this->_ConstructorID = -1684914010;
}

UpdateBotWebhookJSONQuery::UpdateBotWebhookJSONQuery(unsigned long long query_id, COMMON::DataJSON*  data, int32 timeout)
{
	this->_ConstructorID = -1684914010;
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
	data = reinterpret_cast<COMMON::DataJSON* >(Reader.TGReadObject());
	timeout = Reader.ReadInt();
	this->_Responded = true;
}
UpdateBotWebhookJSONQuery::~UpdateBotWebhookJSONQuery()
{
	if(this->data)
	{
		delete this->data;
	}
}
}//end namespace block
