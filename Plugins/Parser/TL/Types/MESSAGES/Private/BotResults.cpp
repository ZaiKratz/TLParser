#include "../Public/BotResults.h"


//begin namespace block
namespace MESSAGES
{

BotResults::BotResults()
{
	this->_ConstructorID = 1029100492;
}

BotResults::BotResults(bool gallery, unsigned long long query_id, FString next_offset, COMMON::InlineBotSwitchPM* switch_pm, TArray<COMMON::BotInlineResult*> results, int32 cache_time)
{
	this->_ConstructorID = 1029100492;
	this->gallery = gallery;
	this->query_id = query_id;
	this->next_offset = next_offset;
	this->switch_pm = switch_pm;
	this->results = results;
	this->cache_time = cache_time;
}
void BotResults::OnSend(BinaryWriter& Writer)
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
	if(!next_offset.IsEmpty())
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!switch_pm)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteLong(this->query_id);
	Writer.TGWriteString(this->next_offset);
	if(!this->switch_pm)
	{
	this->switch_pm->OnSend(Writer);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->results.Num());
	for(auto X : this->results)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(this->cache_time);
}


void BotResults::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		gallery = true;
	}
	query_id = Reader.ReadLong();
	if((Flags & (1 << 1)) != 0) 
	{
	next_offset = Reader.TGReadString();
	}
	if((Flags & (1 << 2)) != 0) 
	{
	switch_pm = reinterpret_cast<COMMON::InlineBotSwitchPM*>(Reader.TGReadObject());
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len9037 = Reader.ReadInt();
	for(int32 i = 0; i < Len9037; i++)
	{
	auto X = reinterpret_cast<COMMON::BotInlineResult*>(Reader.TGReadObject());
	results.Add(X);
	}
	cache_time = Reader.ReadInt();
}
BotResults::~BotResults()
{

}
}//end namespace block
