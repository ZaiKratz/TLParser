#include "../Public/UpdateBotShippingQuery.h"


//begin namespace block
namespace COMMON
{

UpdateBotShippingQuery::UpdateBotShippingQuery()
{
	this->_ConstructorID = 1086967264;
}

UpdateBotShippingQuery::UpdateBotShippingQuery(unsigned long long query_id, int32 user_id, TArray<uint8> payload, COMMON::PostAddress* shipping_address)
{
	this->_ConstructorID = 1086967264;
	this->query_id = query_id;
	this->user_id = user_id;
	this->payload = payload;
	this->shipping_address = shipping_address;
}
void UpdateBotShippingQuery::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->query_id);
	Writer.WriteInt(this->user_id);
	Writer.TGWriteBytes((unsigned char*)this->payload.GetData(), this->payload.Num());
	this->shipping_address->OnSend(Writer);
}


void UpdateBotShippingQuery::OnResponce(BinaryReader& Reader)
{
	query_id = Reader.ReadLong();
	user_id = Reader.ReadInt();
	payload = Reader.TGReadBytes();
	shipping_address = reinterpret_cast<COMMON::PostAddress*>(Reader.TGReadObject());
}
UpdateBotShippingQuery::~UpdateBotShippingQuery()
{

}
}//end namespace block