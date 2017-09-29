#include "../Public/UpdateBotInlineQuery.h"


//begin namespace block
namespace COMMON
{

UpdateBotInlineQuery::UpdateBotInlineQuery()
{
	this->_ConstructorID = 1417832080;
}

UpdateBotInlineQuery::UpdateBotInlineQuery(unsigned long long query_id, int32 user_id, FString query, COMMON::GeoPoint*  geo, FString offset)
{
	this->_ConstructorID = 1417832080;
	this->query_id = query_id;
	this->user_id = user_id;
	this->query = query;
	this->geo = geo;
	this->offset = offset;
}
void UpdateBotInlineQuery::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(geo)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteLong(this->query_id);
	Writer.WriteInt(this->user_id);
	Writer.TGWriteString(this->query);
	if(!this->geo)
	{
	this->geo->OnSend(Writer);
	}
	Writer.TGWriteString(this->offset);
}


void UpdateBotInlineQuery::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	query_id = Reader.ReadLong();
	user_id = Reader.ReadInt();
	query = Reader.TGReadString();
	if((Flags & (1 << 0)) != 0) 
	{
	geo = reinterpret_cast<COMMON::GeoPoint* >(Reader.TGReadObject());
	}
	offset = Reader.TGReadString();
	this->_Responded = true;
}
UpdateBotInlineQuery::~UpdateBotInlineQuery()
{

}
}//end namespace block
