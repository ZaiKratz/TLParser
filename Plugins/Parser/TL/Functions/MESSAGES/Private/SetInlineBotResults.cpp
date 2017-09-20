#include "../Public/SetInlineBotResults.h"


//begin namespace block
namespace MESSAGES
{

SetInlineBotResults::SetInlineBotResults()
{
	this->_ConstructorID = 111304427;
	this->_ContentRelated = true;
}

SetInlineBotResults::SetInlineBotResults(bool gallery, bool Private, unsigned long long query_id, TArray<COMMON::InputBotInlineResult*> results, int32 cache_time, FString next_offset, COMMON::InlineBotSwitchPM* switch_pm)
{
	this->_ConstructorID = 111304427;
	this->_ContentRelated = true;
	this->gallery = gallery;
	this->Private = Private;
	this->query_id = query_id;
	this->results = results;
	this->cache_time = cache_time;
	this->next_offset = next_offset;
	this->switch_pm = switch_pm;
}
void SetInlineBotResults::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!gallery)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!Private)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!next_offset.IsEmpty())
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(!switch_pm)
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteLong(this->query_id);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->results.Num());
	for(auto X : this->results)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(this->cache_time);
	Writer.TGWriteString(this->next_offset);
	if(!this->switch_pm)
	{
	this->switch_pm->OnSend(Writer);
	}
}


void SetInlineBotResults::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
}
SetInlineBotResults::~SetInlineBotResults()
{

}
}//end namespace block
