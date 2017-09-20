#include "../Public/AnswerWebhookJSONQuery.h"


//begin namespace block
namespace BOTS
{

AnswerWebhookJSONQuery::AnswerWebhookJSONQuery()
{
	this->_ConstructorID = 1295983078;
	this->_ContentRelated = true;
}

AnswerWebhookJSONQuery::AnswerWebhookJSONQuery(unsigned long long query_id, COMMON::DataJSON* data)
{
	this->_ConstructorID = 1295983078;
	this->_ContentRelated = true;
	this->query_id = query_id;
	this->data = data;
}
void AnswerWebhookJSONQuery::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->query_id);
	this->data->OnSend(Writer);
}


void AnswerWebhookJSONQuery::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
}
AnswerWebhookJSONQuery::~AnswerWebhookJSONQuery()
{

}
}//end namespace block