#include "../Public/UpdateInlineBotCallbackQuery.h"


//begin namespace block
namespace COMMON
{

UpdateInlineBotCallbackQuery::UpdateInlineBotCallbackQuery()
{
	this->_ConstructorID = 1517998841;
}

UpdateInlineBotCallbackQuery::UpdateInlineBotCallbackQuery(unsigned long long query_id, int32 user_id, COMMON::InputBotInlineMessageID* msg_id, unsigned long long chat_instance, TArray<uint8> data, FString game_short_name)
{
	this->_ConstructorID = 1517998841;
	this->query_id = query_id;
	this->user_id = user_id;
	this->msg_id = msg_id;
	this->chat_instance = chat_instance;
	this->data = data;
	this->game_short_name = game_short_name;
}
void UpdateInlineBotCallbackQuery::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(data.Num())
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!game_short_name.IsEmpty())
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteLong(this->query_id);
	Writer.WriteInt(this->user_id);
	this->msg_id->OnSend(Writer);
	Writer.WriteLong(this->chat_instance);
	if(this->data.Num())
	{
	Writer.TGWriteBytes((unsigned char*)this->data.GetData(), this->data.Num());
	}
	Writer.TGWriteString(this->game_short_name);
}


void UpdateInlineBotCallbackQuery::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	query_id = Reader.ReadLong();
	user_id = Reader.ReadInt();
	msg_id = reinterpret_cast<COMMON::InputBotInlineMessageID*>(Reader.TGReadObject());
	chat_instance = Reader.ReadLong();
	if((Flags & (1 << 0)) != 0) 
	{
	data = Reader.TGReadBytes();
	}
	if((Flags & (1 << 1)) != 0) 
	{
	game_short_name = Reader.TGReadString();
	}
}
UpdateInlineBotCallbackQuery::~UpdateInlineBotCallbackQuery()
{

}
}//end namespace block