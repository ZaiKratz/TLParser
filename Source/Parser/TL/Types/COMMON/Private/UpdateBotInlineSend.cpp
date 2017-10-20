#include "../Public/UpdateBotInlineSend.h"


//begin namespace block
namespace COMMON
{

UpdateBotInlineSend::UpdateBotInlineSend()
{
	this->_ConstructorID = 239663460;
}

UpdateBotInlineSend::UpdateBotInlineSend(int32 user_id, FString query, COMMON::GeoPoint*  geo, FString id, COMMON::InputBotInlineMessageID*  msg_id)
{
	this->_ConstructorID = 239663460;
	this->user_id = user_id;
	this->query = query;
	this->geo = geo;
	this->id = id;
	this->msg_id = msg_id;
}
void UpdateBotInlineSend::OnSend(BinaryWriter& Writer)
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
	if(msg_id)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->user_id);
	Writer.TGWriteString(this->query);
	if(this->geo)
	{
	this->geo->OnSend(Writer);
	}
	Writer.TGWriteString(this->id);
	if(this->msg_id)
	{
	this->msg_id->OnSend(Writer);
	}
}


void UpdateBotInlineSend::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	user_id = Reader.ReadInt();
	query = Reader.TGReadString();
	if((Flags & (1 << 0)) != 0) 
	{
	geo = reinterpret_cast<COMMON::GeoPoint* >(Reader.TGReadObject());
	}
	id = Reader.TGReadString();
	if((Flags & (1 << 1)) != 0) 
	{
	msg_id = reinterpret_cast<COMMON::InputBotInlineMessageID* >(Reader.TGReadObject());
	}
	this->_Responded = true;
}
UpdateBotInlineSend::~UpdateBotInlineSend()
{
	if(this->geo)
	{
		delete this->geo;
	}
	if(this->msg_id)
	{
		delete this->msg_id;
	}
}
}//end namespace block
